package dpo4mvc;

import ui.*;
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
				ViewPanel leftPanel = new GraphicView();
				ViewPanel rightPanel = new TableView();
				MainFrame mainFrame = new MainFrame("MVC", leftPanel, rightPanel);
				mainFrame.setVisible(true);
            }
        });
	}
}