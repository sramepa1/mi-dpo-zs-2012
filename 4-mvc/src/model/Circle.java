/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.awt.Graphics;

/**
 *
 * @author rusty
 */
public class Circle extends Shape {

    public Circle(int x, int y, int r) {
        super(x, y);
        
        initAttribute("R", r, new rAccessor());
    }

    private int r;
	

    @Override
    public String getTypeName() {
        return "Circle";
    }
    
    class rAccessor implements IAttributeAccessor {

        @Override
        public int getAttribute() {
            return r;
        }

        @Override
        public void setAttribute(int value) {
            if(value < 0) {
                throw new IllegalArgumentException("Circle radius can not be negative.");
            }

            r = value;
            notifyListeners();
        }
        
    }
	
	
	@Override
	public void paint(Graphics g) {
		g.drawOval(x, y, 2*r, 2*r);
	}
    
}
