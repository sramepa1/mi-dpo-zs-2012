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
        
        setR(r);
    }

    private int r;
  
    public final void setR(int r) {
        if(r < 0) {
            throw new IllegalArgumentException("Circle radius can not be negative.");
        }
        
        this.r = r;
    }
    
   
    
}
