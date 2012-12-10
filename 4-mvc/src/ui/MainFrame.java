package ui;

import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author pavel
 */
public class MainFrame extends JFrame {
	
	public MainFrame(String title, ViewPanel leftPanel, ViewPanel rightPanel) { // TODO + controller for Clear button.
       super(title);
	   Dimension size = new Dimension(640, 480);
       setSize(size);
	   setMinimumSize(size);
	   setLayout(new BorderLayout());
	   
	   JPanel bottomPanel = new JPanel();
	   bottomPanel.add(new JButton("Clear all"));
	   getContentPane().add(bottomPanel, BorderLayout.PAGE_END);
	   getContentPane().add(leftPanel, BorderLayout.CENTER);
	   getContentPane().add(rightPanel, BorderLayout.LINE_END);
	   
       setLocationRelativeTo(null);
       setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
