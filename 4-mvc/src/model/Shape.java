/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

/**
 *
 * @author rusty
 */
public abstract class Shape {
    
    public Shape(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    protected int x;
    protected int y;
    
    public void setX(int x) {
        this.x = x;
    }
    
    public void setY(int x) {
        this.x = x;
    }
    
    public int getX() {
        return x;
    }
    
    public int getY() {
        return y;
    }
    
}
