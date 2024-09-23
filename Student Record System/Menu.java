/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package package1;

import java.awt.Color;
import java.awt.Cursor;

/**
 *
 * @author markr
 */
public class Menu extends javax.swing.JFrame {

    /**
     * Creates new form Mainframe
     */
    public Menu() {
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

        addrec_button = new javax.swing.JButton();
        mod_button = new javax.swing.JButton();
        out_button = new javax.swing.JButton();
        login_label = new javax.swing.JLabel();
        dis_button = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        addrec_button.setBackground(new java.awt.Color(0, 51, 51));
        addrec_button.setFont(new java.awt.Font("Segoe UI Black", 0, 12)); // NOI18N
        addrec_button.setForeground(new java.awt.Color(255, 255, 255));
        addrec_button.setText("Add a Record");
        addrec_button.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 51, 51)));
        addrec_button.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        addrec_button.setFocusPainted(false);
        addrec_button.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                addrec_buttonMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                addrec_buttonMouseExited(evt);
            }
        });
        addrec_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addrec_buttonActionPerformed(evt);
            }
        });

        mod_button.setBackground(new java.awt.Color(0, 51, 51));
        mod_button.setFont(new java.awt.Font("Segoe UI Black", 0, 12)); // NOI18N
        mod_button.setForeground(new java.awt.Color(255, 255, 255));
        mod_button.setText("Modify Record");
        mod_button.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 51, 51)));
        mod_button.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        mod_button.setFocusPainted(false);
        mod_button.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                mod_buttonMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                mod_buttonMouseExited(evt);
            }
        });
        mod_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mod_buttonActionPerformed(evt);
            }
        });

        out_button.setBackground(new java.awt.Color(0, 51, 51));
        out_button.setFont(new java.awt.Font("Segoe UI Black", 0, 12)); // NOI18N
        out_button.setForeground(new java.awt.Color(255, 255, 255));
        out_button.setText("Sign out");
        out_button.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 51, 51)));
        out_button.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        out_button.setFocusPainted(false);
        out_button.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                out_buttonMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                out_buttonMouseExited(evt);
            }
        });
        out_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                out_buttonActionPerformed(evt);
            }
        });

        login_label.setFont(new java.awt.Font("Segoe UI Black", 0, 36)); // NOI18N
        login_label.setForeground(new java.awt.Color(0, 51, 51));
        login_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        login_label.setText("TUP Student Record");

        dis_button.setBackground(new java.awt.Color(0, 51, 51));
        dis_button.setFont(new java.awt.Font("Segoe UI Black", 0, 12)); // NOI18N
        dis_button.setForeground(new java.awt.Color(255, 255, 255));
        dis_button.setText("Display Record");
        dis_button.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 51, 51)));
        dis_button.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        dis_button.setFocusPainted(false);
        dis_button.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                dis_buttonMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                dis_buttonMouseExited(evt);
            }
        });
        dis_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dis_buttonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(login_label, javax.swing.GroupLayout.DEFAULT_SIZE, 415, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(mod_button, javax.swing.GroupLayout.DEFAULT_SIZE, 235, Short.MAX_VALUE)
                    .addComponent(addrec_button, javax.swing.GroupLayout.DEFAULT_SIZE, 235, Short.MAX_VALUE)
                    .addComponent(out_button, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(dis_button, javax.swing.GroupLayout.DEFAULT_SIZE, 235, Short.MAX_VALUE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(login_label)
                .addGap(18, 18, 18)
                .addComponent(addrec_button, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(mod_button, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(dis_button, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(32, 32, 32)
                .addComponent(out_button, javax.swing.GroupLayout.PREFERRED_SIZE, 19, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(22, Short.MAX_VALUE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void addrec_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addrec_buttonActionPerformed
        Insert_rec add = new Insert_rec();
        add.setVisible(true);
        dispose();
    }//GEN-LAST:event_addrec_buttonActionPerformed

    private void mod_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mod_buttonActionPerformed
        Modify_rec mod = new Modify_rec();
        mod.setVisible(true);
        dispose();
    }//GEN-LAST:event_mod_buttonActionPerformed

    private void out_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_out_buttonActionPerformed
        Login_main log = new Login_main();
        log.setVisible(true);
        dispose();
    }//GEN-LAST:event_out_buttonActionPerformed

    private void addrec_buttonMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addrec_buttonMouseEntered
        addrec_button.setBackground(new Color(255, 255, 255));
        addrec_button.setForeground(new Color(0, 51, 51));
    }//GEN-LAST:event_addrec_buttonMouseEntered

    private void addrec_buttonMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addrec_buttonMouseExited
        addrec_button.setBackground(new Color(0, 51, 51));
        addrec_button.setForeground(new Color(255, 255, 255));
    }//GEN-LAST:event_addrec_buttonMouseExited

    private void mod_buttonMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mod_buttonMouseEntered
        mod_button.setBackground(new Color(255, 255, 255));
        mod_button.setForeground(new Color(0, 51, 51));
    }//GEN-LAST:event_mod_buttonMouseEntered

    private void mod_buttonMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mod_buttonMouseExited
        mod_button.setBackground(new Color(0, 51, 51));
        mod_button.setForeground(new Color(255, 255, 255));
    }//GEN-LAST:event_mod_buttonMouseExited

    private void out_buttonMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_out_buttonMouseEntered
        out_button.setBackground(new Color(255, 255, 255));
        out_button.setForeground(new Color(0, 51, 51));
    }//GEN-LAST:event_out_buttonMouseEntered

    private void out_buttonMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_out_buttonMouseExited
        out_button.setBackground(new Color(0, 51, 51));
        out_button.setForeground(new Color(255, 255, 255));
    }//GEN-LAST:event_out_buttonMouseExited

    private void dis_buttonMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_dis_buttonMouseEntered
        dis_button.setBackground(new Color(255, 255, 255));
        dis_button.setForeground(new Color(0, 51, 51));
    }//GEN-LAST:event_dis_buttonMouseEntered

    private void dis_buttonMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_dis_buttonMouseExited
        dis_button.setBackground(new Color(0, 51, 51));
        dis_button.setForeground(new Color(255, 255, 255));
    }//GEN-LAST:event_dis_buttonMouseExited

    private void dis_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dis_buttonActionPerformed
        Display_rec dis = new Display_rec();
        dis.setVisible(true);
        dispose();
    }//GEN-LAST:event_dis_buttonActionPerformed

    /**
     * @param args the command line arguments
     */

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton addrec_button;
    private javax.swing.JButton dis_button;
    private javax.swing.JLabel login_label;
    private javax.swing.JButton mod_button;
    private javax.swing.JButton out_button;
    // End of variables declaration//GEN-END:variables
}
