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
	   Dimension size = new Dimension(800, 480);
       setSize(size);
	   setMinimumSize(size);
	   setLayout(new BorderLayout());
	   
	   JPanel bottomPanel = new JPanel();
	   JButton clearButton = new JButton("Clear all");
	   JButton moveButton = new JButton("Move all");
	   clearButton.addActionListener(new Nuker(ctrl));
	   moveButton.addActionListener(new Mover(ctrl));
	   bottomPanel.add(clearButton);
	   bottomPanel.add(moveButton);
	   
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
	
	
	protected class Mover implements ActionListener {
		
		protected Controller ctrl;
		
		Mover(Controller ctrl) {
			this.ctrl = ctrl;
		}
		
		protected int rndMove() {
			return (int)(Math.random() * 82) - 42;
		}

		@Override
		public void actionPerformed(ActionEvent ae) {
			ctrl.move(rndMove(), rndMove());
		}
		
	}
}
