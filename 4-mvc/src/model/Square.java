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
public class Square extends Shape {
	
	public static final String SQUARE_TYPE_NAME = "Square";

    public Square(int x, int y, int a) {
        super(x, y);
        
        attributeAccessors.put("A", new aAccessor());
        setAttribute("A", a);
    }

    private int a;
  
    
    @Override
    public String[] getAttributeNames() {
        String[] names = {
            "X", "Y", "A"
        };
        
        return names;
    }

    @Override
    public String getTypeName() {
        return "Square";
    }
    
    
    class aAccessor implements IAttributeAccessor {

        @Override
        public int getAttribute() {
            return a;
        }

        @Override
        public void setAttribute(int value) {
            if(value < 0) {
                throw new IllegalArgumentException("Square side size can not be negative.");
            }

            a = value;
            notifyListeners();
        }
        
    }
	
	
	@Override
	public void paint(Graphics g) {
		g.drawRect(x, y, a, a);
	}
}
