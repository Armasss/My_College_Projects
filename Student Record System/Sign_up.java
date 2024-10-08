/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package package1;

import java.awt.Color;
import java.awt.Cursor;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.regex.Pattern;
import javax.swing.JOptionPane;

/**
 *
 * @author markr
 */
public class Sign_up extends javax.swing.JFrame {

    /**
     * Creates new form Sign_up
     */
    public Sign_up() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        userName = new javax.swing.JTextField();
        login_button = new javax.swing.JButton();
        userPass = new javax.swing.JPasswordField();
        ckbox = new javax.swing.JCheckBox();
        jLabel4 = new javax.swing.JLabel();
        userConfirmPass = new javax.swing.JPasswordField();
        login_click = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setFont(new java.awt.Font("Segoe UI Black", 0, 36)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 51, 51));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("SIGN UP");

        jLabel2.setFont(new java.awt.Font("Segoe UI Light", 0, 12)); // NOI18N
        jLabel2.setText("Username");

        jLabel3.setFont(new java.awt.Font("Segoe UI Light", 0, 12)); // NOI18N
        jLabel3.setText("Password");

        userName.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        login_button.setBackground(new java.awt.Color(0, 51, 51));
        login_button.setFont(new java.awt.Font("Segoe UI Black", 0, 12)); // NOI18N
        login_button.setForeground(new java.awt.Color(255, 255, 255));
        login_button.setText("Create Account");
        login_button.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        login_button.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        login_button.setRequestFocusEnabled(false);
        login_button.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                login_buttonMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                login_buttonMouseExited(evt);
            }
        });
        login_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                login_buttonActionPerformed(evt);
            }
        });

        userPass.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        ckbox.setFont(new java.awt.Font("Segoe UI Light", 0, 12)); // NOI18N
        ckbox.setText("View Password");
        ckbox.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        ckbox.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ckboxActionPerformed(evt);
            }
        });

        jLabel4.setFont(new java.awt.Font("Segoe UI Light", 0, 12)); // NOI18N
        jLabel4.setText("Confirm Password");

        userConfirmPass.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        login_click.setFont(new java.awt.Font("Segoe UI Black", 0, 12)); // NOI18N
        login_click.setText("Login");
        login_click.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                login_clickMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                login_clickMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                login_clickMouseExited(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Segoe UI Light", 0, 12)); // NOI18N
        jLabel6.setText("Have an account?");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(32, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel6)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(login_click))
                    .addComponent(userPass, javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(userName, javax.swing.GroupLayout.PREFERRED_SIZE, 317, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 142, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 142, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 142, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(login_button, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(userConfirmPass, javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(ckbox))
                .addContainerGap(32, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(14, Short.MAX_VALUE)
                .addComponent(jLabel1)
                .addGap(12, 12, 12)
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(userName, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(userPass, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel4)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(userConfirmPass, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(ckbox)
                .addGap(18, 18, 18)
                .addComponent(login_button, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(login_click)
                    .addComponent(jLabel6))
                .addContainerGap(24, Short.MAX_VALUE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents
   private boolean passwordChecker(String password) {
        if (password == null || password.isEmpty()) {
            JOptionPane.showMessageDialog(null, "password cannot be empty", "Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        //password length
        if (password.length() < 8 || password.length() > 20) {
            JOptionPane.showMessageDialog(null, "password must be between 8 to 20 characters", "Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }

        if (!Pattern.compile("[a-z]").matcher(password).find()) {
            JOptionPane.showMessageDialog(null, "Password must contain at least one lower case", "Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }

        if (!Pattern.compile("[A-Z]").matcher(password).find()) {
            JOptionPane.showMessageDialog(null, "Password must contain at least one upper case", "Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        if (!Pattern.compile("[0-9]").matcher(password).find()) {
            JOptionPane.showMessageDialog(null, "Password must contain at least one digit", "Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }

        if (!Pattern.compile("[,.;:'|~`/!@#$%&*()_+=|<>?-]").matcher(password).find()) {
            JOptionPane.showMessageDialog(null, "Password must contain at least one symbol", "Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }

        return true;
    }

    private boolean confirmPassword(String password) {
        String confirmPass = userPass.getText();
        return confirmPass.equals(password);
    }
    private void login_buttonMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_login_buttonMouseEntered
        login_button.setBackground(new Color(255, 255, 255));
        login_button.setForeground(new Color(0, 51, 51));
    }//GEN-LAST:event_login_buttonMouseEntered

    private void login_buttonMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_login_buttonMouseExited
        login_button.setBackground(new Color(0, 51, 51));
        login_button.setForeground(new Color(255, 255, 255));
    }//GEN-LAST:event_login_buttonMouseExited

    private void login_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_login_buttonActionPerformed
        String adminName = userName.getText();
        String adminPass = userPass.getText();
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conDB = DriverManager.getConnection("jdbc:mysql://localhost:3306/isdb", "root", "1234");
            Statement state = conDB.createStatement();
            ResultSet getData = state.executeQuery("SELECT * FROM login_tbl WHERE username = '" + adminName + "'");

            String getUsername = "";

            if (getData.next()) {
                getUsername = getData.getString("username");
            }

            if (adminName.equals("") || adminPass.equals("") || userConfirmPass.getText().equals("")) {
                JOptionPane.showMessageDialog(null, "Please enter username and password", "Error", JOptionPane.ERROR_MESSAGE);
            } else if (adminName.equals(getUsername)) {
                JOptionPane.showMessageDialog(null, "Username already taken", "Error", JOptionPane.ERROR_MESSAGE);
                userName.setText("");
            } else if (passwordChecker(userPass.getText()) == false) {

                userPass.setText("");
                userConfirmPass.setText("");

            } else if (confirmPassword(userConfirmPass.getText()) == false) {
                JOptionPane.showMessageDialog(null, "Password does not match", "Error", JOptionPane.ERROR_MESSAGE);
                userPass.setText(null);
                userConfirmPass.setText(null);

            } else {
                state.executeUpdate("Insert into login_tbl("
                        + "username,password" + ") VALUES ('"
                        + userName.getText() + "','"
                        + userPass.getText() + "')");
                JOptionPane.showMessageDialog(null, "Account Created",
                        "System Message", JOptionPane.INFORMATION_MESSAGE);
                Login_main log = new Login_main();
                log.setVisible(true);
                dispose();
            }
        } catch (Exception e) {
            ///e
            System.out.print("proceed to main");
        }
    }//GEN-LAST:event_login_buttonActionPerformed

    private void ckboxActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ckboxActionPerformed
        if (ckbox.isSelected()) {
            userPass.setEchoChar((char) 0);
            userConfirmPass.setEchoChar((char) 0);
        } else {
            userPass.setEchoChar('\u2022');
            userConfirmPass.setEchoChar('\u2022');
        }
    }//GEN-LAST:event_ckboxActionPerformed

    private void login_clickMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_login_clickMouseClicked
        Login_main log = new Login_main();
        log.setVisible(true);
        dispose();
    }//GEN-LAST:event_login_clickMouseClicked

    private void login_clickMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_login_clickMouseEntered
        login_click.setForeground(new java.awt.Color(0, 51, 51));
        login_click.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_login_clickMouseEntered

    private void login_clickMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_login_clickMouseExited
        login_click.setForeground(new java.awt.Color(0, 0, 0));
    }//GEN-LAST:event_login_clickMouseExited

    /**
     * @param args the command line arguments
     */


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JCheckBox ckbox;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JButton login_button;
    private javax.swing.JLabel login_click;
    private javax.swing.JPasswordField userConfirmPass;
    private javax.swing.JTextField userName;
    private javax.swing.JPasswordField userPass;
    // End of variables declaration//GEN-END:variables
}
