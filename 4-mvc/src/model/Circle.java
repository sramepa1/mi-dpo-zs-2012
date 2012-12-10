/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

/**
 *
 * @author rusty
 */
public class Circle extends Shape {

    Circle(int x, int y, int r) {
        super(x, y);
        
        attributeAccessors.put("R", new rAccessor());
        setAttribute("R", r);
    }

    private int r;
  
    
    @Override
    public String[] getAttributeNames() {
        String[] names = {
            "X", "Y", "R"
        };
        
        return names;
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
    
}
