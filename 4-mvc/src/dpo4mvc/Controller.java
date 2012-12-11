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
	
	public void move(int xOffset, int yOffset) {
		for(Shape s : model.getAllShapes()) {
			s.setAttribute("X", s.getAttribute("X") + xOffset);
			s.setAttribute("Y", s.getAttribute("Y") + yOffset);
		}
	}
	
	public void addShape(Shape s) {
		try {
			model.addShape(s);
		} catch (IllegalArgumentException e) {
			JOptionPane.showMessageDialog(mainFrame, e.getMessage(), "Unable to add new shape", JOptionPane.WARNING_MESSAGE);
		}
	}
	
	public void setShapeAttribute(String typeName, int id, String attributeName, int value) {
		try {
			model.getShape(typeName, id).setAttribute(attributeName, value);
		} catch (IllegalArgumentException e) {
			JOptionPane.showMessageDialog(mainFrame, e.getMessage(), "Illegal argument", JOptionPane.WARNING_MESSAGE);
		}		
	}
	
}
