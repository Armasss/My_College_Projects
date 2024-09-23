//Created by: Mark Rainier Armas and Uriel Papa
//BSIS 2A DSA

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "design.h"

using namespace std;

struct NodeData // tree
{
    char data;
    long long frequency;
    NodeData* left;
    NodeData* right;
    NodeData(char c, long long freq) : data(c), frequency(freq), left(NULL), right(NULL) {}
};

struct Node //  queue
{
    NodeData* node;
    Node* next;
    Node(NodeData* bn) : node(bn), next(NULL) {}
};

class Compression
{
private:
    Node* head;
    NodeData* root;
    string codes[256];
    string binCode = "";
    string copyOfQueue = "";
    string fileName;
    string outfileName;
    string compressedExtension = ".uspmra"; //our own compressed file extension
public:
    Compression() : head(NULL), root(NULL) {}

    void enqueue(NodeData* data)//for priorityqueue
    {
        Node* newNode = new Node(data);

        if (head == NULL || newNode->node->frequency < head->node->frequency)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next && newNode->node->frequency >= current->next->node->frequency)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    NodeData* dequeue() //for building the huff tree, returns a treenode;
    {
        Node* temp = head;
        NodeData* treenode = temp->node;
        head = head->next;
        delete temp;
        return treenode;
    }

    void buildtree()//process for building the tree when all the characters in the file are enqueued
    {
        while (head->next != NULL)
        {
            NodeData* first, * second, * NewNode;
            first = dequeue();
            second = dequeue();
            NewNode = new NodeData('\0', first->frequency + second->frequency);
            NewNode->left = first;
            NewNode->right = second;
            enqueue(NewNode);
        }
        root = dequeue();
    }
    void getHuffmanCodes(NodeData* root, string code)//gets the huffman codes for each char after the tree is built.
    {
        if (root == NULL)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            codes[root->data] = code;
        }

        getHuffmanCodes(root->left, code + "0");
        getHuffmanCodes(root->right, code + "1");
    }
    void textToCode()//converts the chars in the text to their respective huffman codes
    {
        ifstream fileptr(fileName);
        char ch;
        while (fileptr.get(ch))
        {
            if (ch >= 0 && ch <= 255)
            {
                binCode += codes[ch];
            }
        }
        fileptr.close();
    }
    bool getFileName()//to ask the user for the file name
    {
        clearArea(41,11,39,8);
        gotoxy(47,13);
        setColor(7);
        cout << "Enter the name of the file";
        gotoxy(47,14);
        setColor(7);
        cout << "Example: File.txt";
        gotoxy(47,15);
        setColor(7);
        showcursor();
        cout << "File name:";
        getline(cin >> ws, fileName);
        return checkFile(fileName);
    }
    bool checkFile(string fileN)//checks if the file is available, the file must not be a compressed file (file with huff extension).
    {
        hidecursor();
        if(fileN.find(compressedExtension) != string::npos)
        {
            clearArea(41,11,39,8);
            gotoxy(49,14);
            setColor(4);
            cout << "Invalid file type...";
            Sleep(2000);
            return false;
        }

        ifstream file(fileN);

        if(file.is_open())
        {
            clearArea(41,11,39,8);
            gotoxy(55,14);
            setColor(2);
            cout << "File Found!";
            Sleep(2000);
            file.close();
            return true;
        }
        else
        {
            clearArea(41,11,39,8);
            gotoxy(51,14);
            setColor(4);
            cout << "File not found...";
            Sleep(2000);
            file.close();
            return false;
        }

    }
    void processFile()//reads the original file, counts char frequencies, makes the hufftree, gets the huffcodes and gets the completed binary code of the text.
    {
        hidecursor();
        clearArea(41,11,39,8);
        NodeData* newNode;
        long long characters[256];

        for (int i = 0; i < 256; i++)
        {
            characters[i] = 0;
        }

        char ch;

        ifstream fileptr(fileName);
        clearArea(41,11,39,8);
        gotoxy(49,14);
        setColor(6);
        cout << "[COMPRESSING THE FILE]";
        while (fileptr.get(ch))
        {
            characters[ch]++;
        }
        fileptr.close();

        for (int i = 0; i < 256; i++)
        {
            if (characters[i] != 0)
            {
                newNode = new NodeData(char(i), characters[i]);
                enqueue(newNode);
            }
        }
        storeQueue();
        buildtree();
        getHuffmanCodes(root, "");
        textToCode();

    }

    void storeQueue()//makes a copy of the complete queue before building the tree, to be used as the tree information for the compressed file.
    {
        Node* p = head;
        while (p != NULL)
        {
            copyOfQueue += p->node->data + to_string(p->node->frequency) + " ";
            p = p->next;
        }
    }

    /*writes the copy of the queue, padding(no. of zeroes added to the complete binarycode), original file extension and the binary code
    that was divided into bytes which was represented into ascii chars with equivalent decimal value for those each byte*/
    void createCompressedFile()
    {
        outfileName = fileName.substr(0, fileName.find_last_of('.')) + compressedExtension;

        ofstream outfile(outfileName, ios::binary);

        outfile.write(copyOfQueue.c_str(), copyOfQueue.size());

        char buff[1];
        char null = '\0';

        int padding = 0;
        if (binCode.length() % 8 != 0)
        {
            padding = 8 - (binCode.length() % 8);
            for (int i = 0; i < padding; i++)
                binCode = "0" + binCode;
        }

        char pad = padding +'0';
        outfile.write(&null, 1);
        outfile.write(&pad, 1);
        outfile.write(&null, 1);
        outfile.write(&null, 1);

        string extension = fileName.substr(fileName.find_last_of('.')+1);// needs sto read the input file and get the extension

        outfile.write(extension.c_str(), extension.size());
        outfile.write(&null, 1);
        outfile.write(&null, 1);

        int dec;
        for (size_t j = 0; j < binCode.length(); j += 8)
        {
            string tmp_bin = binCode.substr(j, 8);
            dec = stoi(tmp_bin, nullptr, 2);
            buff[0] = dec;
            outfile.write(buff, 1);
        }
        outfile.close();
        remove(fileName.c_str());

    }


    void reset()//resets all important data for compression, used so that multiple files can be compressed when running the program.
    {
        head = NULL;
        root = NULL;
        binCode = "";
        copyOfQueue = "";
        fileName = "";
        outfileName = "";

        for(int i=0; i < 256; i++)
            codes[i] = "";
    }

    void menu()//simple menu, asks the user if they want to compress a file or exit the program.
    {
        createBox(40, 10, 41, 10, 5);  // Adjust the coordinates and size as needed
        int choice;
        do
        {
            clearArea(41,11,39,8);
            gotoxy(53,12);
            setColor(15);
            cout << "[ COMPRESSION ]";
            gotoxy(47, 14);
            cout << "[1] Compress a file\n";
            gotoxy(47, 15);
            cout << "[2] Exit\n";
            gotoxy(47, 16);
            cout << "Enter your choice: ";
            choice = getche();
            hidecursor();

            switch (choice)
            {
            case '1':
                if (!getFileName()) break;
                processFile();
                createCompressedFile();
                clearArea(41,11,39,8);
                gotoxy(46,14);
                setColor(2);
                cout << "File compressed successfully!";
                reset();
                Sleep(2000);
                break;
            case '2':
                clearArea(41,11,39,8);
                gotoxy(53,14);
                setColor(4);
                cout << "Exiting program.";
                gotoxy(0,20);
                break;
            default:
                clearArea(41,11,39,8);
                gotoxy(44,14);
                setColor(4);
                cout << "Invalid choice. Please try again.";
                Sleep(2000);
                clearArea(41,11,39,8);
            }
        }
        while (choice != '2');
    }
};

int main()
{
    Compression HT;
    HT.menu();

    return 0;
}
