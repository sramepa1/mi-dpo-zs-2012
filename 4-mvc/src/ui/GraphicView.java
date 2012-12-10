package ui;

import dpo4mvc.Controller;
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import model.Model;

/**
 *
 * @author pavel
 */
public class GraphicView extends JPanel implements IView {
	
	protected Model model;
	protected Controller ctrl;
	
	public GraphicView(Model model, Controller ctrl) {
		super(true);
		this.model = model;
		this.ctrl = ctrl;
		setMinimumSize(new Dimension(160, 160));
		setBackground(Color.WHITE);
		setBorder(BorderFactory.createLineBorder(Color.black, 2));
	}

	@Override
	public void notifyChange() {
		throw new UnsupportedOperationException("Not supported yet.");
	}
	
}
