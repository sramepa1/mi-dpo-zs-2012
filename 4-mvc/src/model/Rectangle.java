package model;

import java.awt.Graphics;

/**
 *
 * @author pavel
 */
public class Rectangle extends Shape {

    public Rectangle(int x, int y, int a, int b) {
        super(x, y);
        
        initAttribute("A", a, new aAccessor());
		initAttribute("B", b, new bAccessor());
    }

    private int a;
	private int b;
	

    @Override
    public String getTypeName() {
        return "Rectangle";
    }
    
    
    class aAccessor implements IAttributeAccessor {

        @Override
        public int getAttribute() {
            return a;
        }

        @Override
        public void setAttribute(int value) {
            if(value < 0) {
                throw new IllegalArgumentException("Rectangle horizontal side size can not be negative.");
            }

            a = value;
            notifyListeners();
        }        
    }
	
	
	class bAccessor implements IAttributeAccessor {

        @Override
        public int getAttribute() {
            return b;
        }

        @Override
        public void setAttribute(int value) {
            if(value < 0) {
                throw new IllegalArgumentException("Rectangle vertical side size can not be negative.");
            }

            b = value;
            notifyListeners();
        }        
    }
	
	
	@Override
	public void paint(Graphics g) {
		g.drawRect(x, y, a, b);
	}
	
}
