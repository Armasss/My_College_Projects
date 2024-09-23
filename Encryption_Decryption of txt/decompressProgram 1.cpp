//Created by: Mark Rainier Armas and Uriel Papa
//BSIS 2A DSA

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "design.h"

using namespace std;

// NodeData structure represents nodes in the Huffman tree
struct NodeData // tree
{
    char data;              // Character data stored in the node
    long long frequency;    // Frequency of the character
    NodeData* left;         // Pointer to the left child node
    NodeData* right;        // Pointer to the right child node
    // Constructor to initialize NodeData with character and frequency
    NodeData(char c, long long freq) : data(c), frequency(freq), left(NULL), right(NULL) {}
};

// Node structure represents nodes in the queue for Huffman tree construction
struct Node // queue
{
    NodeData* node;         // Pointer to a NodeData instance
    Node* next;             // Pointer to the next node in the queue
    // Constructor to initialize Node with a NodeData instance
    Node(NodeData* bn) : node(bn), next(NULL) {}
};

class Decompression
{
private:
    Node* head;           // Head of the linked list used as a priority queue
    NodeData* root;       // Root of the Huffman tree
    string codes[256];    // Array to store Huffman codes for each character
    string binCode;           // Binary representation of the encoded text
    string origExtension;
    string compressedExtension = ".uspmra";
    string padding;
    string compressedFile;
    string decompressedFile;

public:
    Decompression() : head(nullptr), root(nullptr) {}

    // Function to enqueue a NodeData into the priority queue
    void enqueue(NodeData* data)
    {
        Node* newNode = new Node(data);

        // If the queue is empty or the new node has lower frequency, insert at the beginning
        if (head == NULL || newNode->node->frequency < head->node->frequency)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            // Otherwise, find the correct position and insert
            Node* current = head;
            while (current->next && newNode->node->frequency >= current->next->node->frequency)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to dequeue a NodeData from the priority queue
    NodeData* dequeue()
    {
        Node* temp = head;
        NodeData* treenode = temp->node;
        head = head->next;
        delete temp;
        return treenode;
    }

    // Function to build the Huffman tree from the priority queue
    void buildtree()
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

    // Function to generate Huffman codes for each character in the tree
    void getHuffmanCodes(NodeData* root, string code)
    {
        if (root == NULL)
        {
            return;
        }

        // If the current node is a leaf, store its Huffman code
        if (!root->left && !root->right)
        {
            codes[root->data] = code;
        }

        // Recursively traverse the left and right subtrees
        getHuffmanCodes(root->left, code + "0");
        getHuffmanCodes(root->right, code + "1");
    }

    // Function to convert a decimal number to a binary string
    string dectobin(int decimal)
    {
        string s = "";
        for (int i = 7; i >= 0; i--)
        {
            // Check if the i-th bit is set (1) or not (0)
            if (decimal >> i & 1)
                s += '1';
            else
                s += '0';
        }
        return s;
    }

    // Function to read characters and frequencies from a file and populate the priority queue
    void readQueue(ifstream& compFile)
    {
        char buff[1], character = '\0';
        string dec;

        while (compFile.read(buff, 1))
        {
            if (buff[0] == '\0')
            {
                break;
            }
            if (buff[0] >= 0 && buff[0] <= 255 && character == '\0')
            {
                character = buff[0];
            }
            else if (buff[0] == 32)
            {
                enqueue(new NodeData(character, stoi(dec)));
                dec.clear();
                character = '\0';
            }
            else
            {
                dec += buff[0];
            }
        }
    }


    // Function to recursively decode the Huffman binary string
    string decodeHuffmanRecursive(NodeData* root, const string& bin, int& index)
    {
        string decodedText = "";
        while (index <= bin.length())
        {
            // If a leaf node is reached, append the decoded character and reset to the root
            if (!root->left && !root->right)
            {
                decodedText += root->data;
                root = this->root; // Reset root to the top for the next character
            }
            char bit = bin[index++];
            // Move to the left or right child based on the bit value
            if (bit == '0')
            {
                root = root->left;
            }
            else if (bit == '1')
            {
                root = root->right;
            }
        }
        return decodedText;
    }

    // Function to decode the Huffman binary string and write the output to a file
    void decodeHuffmanToFile(const string& bin, const string& decompFile)
    {
        ofstream outputFile(decompFile);

        int index = 0;
        // Iterate through the binary string and decode characters
        while (index < bin.length())
        {

            outputFile << decodeHuffmanRecursive(root, bin, index);
        }

        outputFile.close();
    }

    // Function to let the user enter the name of the file to be decompressed
    bool getFileName()
    {
            clearArea(41,11,39,8);
            gotoxy(47,13);setColor(7);
            cout << "Enter the name of the file";
            gotoxy(47,14);setColor(7);
            cout << "Example: File.uspmra";
            gotoxy(47,15);setColor(7); showcursor();
            cout << "File name:";
            getline(cin >> ws, compressedFile);
            return checkFile(compressedFile);
    }
    bool checkFile(string fileN)
    {
        hidecursor();
        ifstream file(fileN);
        if(fileN.find(compressedExtension) == string::npos)
        {
            clearArea(41,11,39,8);
            gotoxy(49,14);setColor(4);
            cout << "Invalid file type...";
            Sleep(2000);
            return false;
        }

        if(file.is_open())
        {
            clearArea(41,11,39,8);
            gotoxy(55,14);setColor(2);
            cout << "File Found!";
            Sleep(2000);
            file.close();
            return true;
        }
        else
        {
            clearArea(41,11,39,8);
            gotoxy(51,14);setColor(4);
            cout << "File not found...";
            Sleep(2000);
            file.close();
            return false;
        }

    }
    void readCompressedFile()
    {
        clearArea(41,11,39,8);
        ifstream input(compressedFile, ios::binary);
        gotoxy(47,14);setColor(6);
        cout << "[DECOMPRESSING THE FILE]";
        readQueue(input);

        char buff[1];

        input.read(buff, 1);
        int padding = buff[0] - '0';
        input.read(buff, 1);
        input.read(buff, 1);


        while (input.read(buff, 1))
        {
            if (buff[0] == '\0') break;
            origExtension += buff[0];
        }
        origExtension = "." + origExtension;

        input.read(buff, 1);

        while (input.read(reinterpret_cast<char*>(buff), 1))
        {
            // Get decimal (ASCII) equivalent of character
            int decimal = buff[0];

            // Convert to binary and print to the output file
            string binaryEquivalent = dectobin(decimal);
            binCode += binaryEquivalent;
        }

        if(padding != 0)
            binCode = binCode.substr(padding);

        input.close();
    }

    void recreateOriginalFile()
    {
        buildtree();
        getHuffmanCodes(root, "");
        decompressedFile = compressedFile.substr(0, compressedFile.find_last_of('.')) + origExtension;
        decodeHuffmanToFile(binCode, decompressedFile);
        remove(compressedFile.c_str());
    }
    void reset()
    {
        head = NULL;
        root = NULL;
        binCode = "";
        origExtension = "";
        padding = "";
        compressedFile = "";
        decompressedFile = "";

        for(int i=0; i < 256; i++)
            codes[i] = "";

    }

        void menu() {
        createBox(40, 10, 41, 10, 5);  // Adjust the coordinates and size as needed
        int choice;
        do {
            clearArea(41,11,39,8);
            gotoxy(51,12); setColor(15);
            cout << "[ DECOMPRESSION ]";
            gotoxy(47, 14);
            cout << "[1] Decompress a file\n";
            gotoxy(47, 15);
            cout << "[2] Exit\n";
            gotoxy(47, 16);
            cout << "Enter your choice: ";
            choice=getche(); hidecursor();
            switch (choice)
            {
            case '1':
                if(getFileName() == false)break;
                readCompressedFile();
                recreateOriginalFile();
                clearArea(41,11,39,8);
                gotoxy(44,14);setColor(2);
                cout << "File Decompressed successfully!";
                reset();
                Sleep(2000);
                break;
            case '2':
                    clearArea(41,11,39,8);
                    gotoxy(53,14);setColor(4);
                    cout << "Exiting program.";
                    gotoxy(0,20);
                    break;
            default:
                    clearArea(41,11,39,8);
                    gotoxy(44,14);setColor(4);
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
    Decompression HT;
    HT.menu();

    return 0;
}

