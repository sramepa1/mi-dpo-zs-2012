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
		model.addShapeType(Circle.CIRCLE_TYPE_NAME);
		model.addShapeType(Square.SQUARE_TYPE_NAME);
		
		
		
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