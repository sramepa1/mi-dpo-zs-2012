package dpo4mvc;

import ui.*;
import model.*;
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
		
		final Controller ctrl = new Controller();
		final Model model = new Model(ctrl);
		ctrl.setModel(model);
		model.registerPrototype(new Circle(0, 0, 0));
		model.registerPrototype(new Square(0, 0, 0));
		model.registerPrototype(new Rectangle(0, 0, 0, 0));
		
		
		
		SwingUtilities.invokeLater(new Runnable() {
			@Override
            public void run() {
				GraphicView leftPanel = new GraphicView(model, ctrl);
				TableViewPanel rightPanel = new TableViewPanel(model);
				model.addView(leftPanel);
				MainFrame mainFrame = new MainFrame("MVC", leftPanel, rightPanel, ctrl);
				mainFrame.setVisible(true);
            }
        });
	}
}