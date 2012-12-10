/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo4mvc;

import javax.swing.JLabel;
import javax.swing.SwingUtilities;

/**
 *
 * @author pavel
 */
public class Main {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		
		SwingUtilities.invokeLater(new Runnable() {
			@Override
            public void run() {
				MainFrame mainFrame = new MainFrame("MVC");
				// TODO add views
				mainFrame.getContentPane().add(new JLabel("Hello, world!"));
				mainFrame.setVisible(true);
            }
        });
	}
}