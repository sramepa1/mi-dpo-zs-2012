/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.util.ArrayList;

/**
 *
 * @author rusty
 */
public abstract class Shape {
    
    public Shape(int x, int y) {
        this.x = x;
        this.y = y;
        
        this.listeneters = new ArrayList<NitifiablePair>();
    }
    
    protected int x;
    protected int y;
    
    private ArrayList<NitifiablePair> listeneters;
    
    public void setX(int x) {
        this.x = x;
        notifyListeners();
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
    
    public void addListener(INotifiable listener, Object mark) {
        listeneters.add(new NitifiablePair(listener, mark));
    }
    
    protected void notifyListeners() {
        for(NitifiablePair pair : listeneters) {
            pair.listener.reportChange(this, pair.mark);
        }
    }
    
    class NitifiablePair{
        public NitifiablePair(INotifiable first, Object second) {
            this.listener = first;
            this.mark = second;
        }
        
        INotifiable listener;
        Object mark;
    }
    
    public abstract String[] getAttributeNames();
    
}
