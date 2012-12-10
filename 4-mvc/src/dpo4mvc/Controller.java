package dpo4mvc;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import model.Model;
import model.Shape;

/**
 *
 * @author pavel
 */
public class Controller {
	
	protected Model model;
	protected JFrame mainFrame;
	
	public void setModel(Model model) {
		this.model = model;
	}
	
	public void setMainFrame(JFrame frame) {
		mainFrame = frame;
	}
	
	
	public void nuke() {
		model.clearAll();
	}
	
	public void addShape(Shape s) {
		model.addShape(s);
	}
	
	public void setShapeAttribute(String typeName, int id, String attributeName, int value) {
		try {
			model.setShapeAttribute(typeName, id, attributeName, value);
		} catch (IllegalArgumentException e) {
			JOptionPane.showMessageDialog(mainFrame, e.getMessage(), "Illegal argument", JOptionPane.WARNING_MESSAGE);
		}		
	}
	
}
