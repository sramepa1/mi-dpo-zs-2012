/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

/**
 *
 * @author rusty
 */
public class Square extends Shape {

    Square(int x, int y, int a) {
        super(x, y);
        
        setA(a);
    }

    private int a;
  
    public final void setA(int a) {
        if(a < 0) {
            throw new IllegalArgumentException("Square side size can not be negative.");
        }
        
        this.a = a;
        notifyListeners();
    }

    @Override
    public String[] getAttributeNames() {
        String[] names = {
            "X", "Y", "A"
        };
        
        return names;
    }
    
}
