/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import ui.IView;


/**
 *
 * @author rusty
 */
public class Model implements INotifiable {
    
    Model() {
        this.shapesByTypes = new HashMap<String, ArrayList<Shape>>();
        this.viewsByTypes = new HashMap<String, ArrayList<IView>>();
    }
    
    
    
    private HashMap<String, ArrayList<Shape>> shapesByTypes;
    
    private HashMap<String, ArrayList<IView>> viewsByTypes;;
    
   
    
    public void addShapeType(String typeName) {
        if(shapesByTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("This type of shapes already exists.");
        }
        
        shapesByTypes.put(typeName, new ArrayList<Shape>());
    }
    
    public int addShape(String typeName, Shape shape) {
        if(!shapesByTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("Unknown shape type.");
        }
        
        ArrayList<Shape> shapeStorage = shapesByTypes.get(typeName);
        shapeStorage.add(shape);
        
        shape.addListener(this, typeName);
        
        return shapeStorage.size() - 1;
    }
    
    public void clearAll() {
        for (Map.Entry<String, ArrayList<Shape>> entry : shapesByTypes.entrySet())
        {
            entry.setValue(new ArrayList<Shape>());
        }
    }
    
    public Iterable<String> getShapeTypes() {
        LinkedList<String> types = new LinkedList<String>();
        
        for (Map.Entry<String, ArrayList<Shape>> entry : shapesByTypes.entrySet())
        {
            types.add(entry.getKey());
        }
        
        return types;
    }
    
    public Shape getShape(String typeName, int id) {   
        if(!shapesByTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("Unknown shape type.");
        }
        
        return shapesByTypes.get(typeName).get(id);
    }
    
    public Iterable<Shape> getAllShapes(String typeName) {
        if(!shapesByTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("Unknown shape type.");
        }
        
        return (Iterable<Shape>) shapesByTypes.get(typeName).clone();
    }
    
    
    
    public void addView(IView view) {
        for (Map.Entry<String, ArrayList<Shape>> entry : shapesByTypes.entrySet())
        {
            addViewByType(entry.getKey(), view);
        }
    }
    
    public void addViewByType(String typeName, IView view) {
        ArrayList<IView> listeningViews = viewsByTypes.get(typeName);
        
        if(listeningViews == null) {
            listeningViews = new ArrayList<IView>();
            viewsByTypes.put(typeName, listeningViews);
        }
        
        listeningViews.add(view);
    }

    @Override
    public void reportChange(Object changed, Object mark) {
        
        String changedType = (String) mark;
        ArrayList<IView> listeningViews = viewsByTypes.get(changedType);
        
        for(IView view : listeningViews) {
            view.notifyChange();
        }
    }

}
