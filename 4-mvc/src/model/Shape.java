/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.awt.Graphics;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author rusty
 */
public abstract class Shape {
    
    public Shape(int x, int y) {
        this.x = x;
        this.y = y;
        
        this.listeneters = new ArrayList<NotifiablePair>();
        this.attributeAccessors = new HashMap<String, IAttributeAccessor>();
        
        attributeAccessors.put("X", new xAccessor());
        attributeAccessors.put("Y", new yAccessor());
        
        setAttribute("X", x);
        setAttribute("Y", y);
    }
    
    protected int x;
    protected int y;
    
    
    private ArrayList<NotifiablePair> listeneters;
    
    public void addListener(INotifiable listener, Object mark) {
        listeneters.add(new NotifiablePair(listener, mark));
    }
    
    protected void notifyListeners() {
        for(NotifiablePair pair : listeneters) {
            pair.listener.reportChange(this, pair.mark);
        }
    }
    
    class NotifiablePair {
        public NotifiablePair(INotifiable first, Object second) {
            this.listener = first;
            this.mark = second;
        }
        
        INotifiable listener;
        Object mark;
    }
    
    
    public abstract String getTypeName();
    public abstract String[] getAttributeNames();
    
    protected HashMap<String, IAttributeAccessor> attributeAccessors;
    
    protected interface IAttributeAccessor {
        int getAttribute();
        void setAttribute(int value);
    }
    
    public final int getAttribute(String attributeName) {
        return attributeAccessors.get(attributeName).getAttribute();
    }
    
    public final void setAttribute(String attributeName, int value) {
        attributeAccessors.get(attributeName).setAttribute(value);
    }
    
    
    class xAccessor implements IAttributeAccessor {

        @Override
        public int getAttribute() {
            return x;
        }

        @Override
        public void setAttribute(int value) {
            x = value;
            notifyListeners();
        }
        
    }
    
    class yAccessor implements IAttributeAccessor {

        @Override
        public int getAttribute() {
            return y;
        }

        @Override
        public void setAttribute(int value) {
            y = value;
            notifyListeners();
        }
        
    }
    
	
	
	public abstract void paint(Graphics g);
	
}
