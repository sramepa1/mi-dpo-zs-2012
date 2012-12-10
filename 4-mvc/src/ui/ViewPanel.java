package ui;

import javax.swing.JPanel;

/**
 *
 * @author pavel
 */
public abstract class ViewPanel extends JPanel implements IView {
	
	public ViewPanel() {
		super();
	}
	
	public ViewPanel(boolean doubleBuffered) {
		super(doubleBuffered);
	}
	
	// todo Controller link, model link
}
