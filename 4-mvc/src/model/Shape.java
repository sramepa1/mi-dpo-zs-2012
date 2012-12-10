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
        
        this.listeneters = new ArrayList<INotifiable>();
        this.attributeAccessors = new HashMap<String, IAttributeAccessor>();
		this.attributeNames = new ArrayList<String>();
        
		initAttribute("X", x, new xAccessor());
		initAttribute("Y", y, new yAccessor());
    }
    
    protected int x;
    protected int y;
    
    
    private ArrayList<INotifiable> listeneters;
    
    public void addListener(INotifiable listener) {
        listeneters.add(listener);
    }
    
    protected void notifyListeners() {
        for(INotifiable listener : listeneters) {
            listener.reportChange(this);
        }
    }    
    
    public abstract String getTypeName();
	
	protected ArrayList<String> attributeNames;
	
	
    public String[] getAttributeNames() {
		return (String[]) attributeNames.toArray();
	}
    
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
	
	public final void initAttribute(String attributeName, int value, IAttributeAccessor accessor) {
		attributeAccessors.put(attributeName, accessor);
        setAttribute(attributeName, value);
		attributeNames.add(attributeName);
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
