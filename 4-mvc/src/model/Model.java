/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;


/**
 *
 * @author rusty
 */
public class Model {
    
    Model() {
        shapeTypes = new HashMap<String, ArrayList<Shape>>();
    }
    
    private HashMap<String, ArrayList<Shape>> shapeTypes;
    
    public void addShapeType(String typeName) {
        if(shapeTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("This type of shapes already exists.");
        }
        
        shapeTypes.put(typeName, new ArrayList<Shape>());
    }
    
    public void addShape(String typeName, Shape shape) {
        if(!shapeTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("Unknown shape type.");
        }
        
        shapeTypes.get(typeName).add(shape);
    }
    
    public void clearAll() {
        for (Map.Entry<String, ArrayList<Shape>> entry : shapeTypes.entrySet())
        {
            entry.setValue(new ArrayList<Shape>());
        }
    }
    
    public Iterable<String> getShapeTypes() {
        LinkedList<String> types = new LinkedList<String>();
        
        for (Map.Entry<String, ArrayList<Shape>> entry : shapeTypes.entrySet())
        {
            types.add(entry.getKey());
        }
        
        return types;
    }
    
    public Shape getShape(String typeName, int id) {   
        if(!shapeTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("Unknown shape type.");
        }
        
        return shapeTypes.get(typeName).get(id);
    }
    
    public Iterable<Shape> getAllShapes(String typeName) {
        if(!shapeTypes.containsKey(typeName)) {
            throw new IllegalArgumentException("Unknown shape type.");
        }
        
        return (Iterable<Shape>) shapeTypes.get(typeName).clone();
    }

}
