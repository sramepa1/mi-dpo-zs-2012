package ui;

import dpo4mvc.IView;
import dpo4mvc.Controller;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import model.Circle;
import model.Model;
import model.Rectangle;
import model.Shape;
import model.Square;

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
		
		addMouseListener(new Clicker(ctrl));
	}

	@Override
	public void notifyChange() {
		repaint();
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		for(Shape shape : model.getAllShapes()) {
			shape.paint(g);
		}
	}
	
	
	protected class Clicker extends MouseAdapter {
		
		protected Controller ctrl;
		
		public Clicker(Controller ctrl) {
			this.ctrl = ctrl;
		}
		
		protected int rnd() {
			return (int) (Math.random() * 42);
		}

        @Override
        public void mousePressed(MouseEvent e) {
            switch(e.getButton()) {
				case MouseEvent.BUTTON1:
					ctrl.addShape(new Circle(e.getX(), e.getY(), rnd() ));
					break;
				case MouseEvent.BUTTON2:
					ctrl.addShape(new Rectangle(e.getX(), e.getY(), rnd(), rnd()));
					break;
				case MouseEvent.BUTTON3:
					ctrl.addShape(new Square(e.getX(), e.getY(), rnd() ));
					break;
					
				default:
					return;
			}
        }
		
    }
	
}
