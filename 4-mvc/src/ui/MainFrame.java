package ui;

import dpo4mvc.Controller;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author pavel
 */
public class MainFrame extends JFrame {
	
	public MainFrame(String title, JPanel leftPanel, JPanel rightPanel, Controller ctrl) {
       super(title);
	   Dimension size = new Dimension(640, 480);
       setSize(size);
	   setMinimumSize(size);
	   setLayout(new BorderLayout());
	   
	   JPanel bottomPanel = new JPanel();
	   JButton clearButton = new JButton("Clear all");
	   clearButton.addActionListener(new Nuker(ctrl));
	   bottomPanel.add(clearButton);
	   
	   getContentPane().add(bottomPanel, BorderLayout.PAGE_END);
	   getContentPane().add(leftPanel, BorderLayout.CENTER);
	   getContentPane().add(rightPanel, BorderLayout.LINE_END);
	   
       setLocationRelativeTo(null);
       setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
	
	
	protected class Nuker implements ActionListener {
		
		protected Controller bigRedButton;
		
		Nuker(Controller ctrl) {
			bigRedButton = ctrl;
		}

		@Override
		public void actionPerformed(ActionEvent ae) {
			bigRedButton.nuke();
		}
		
	}
}
