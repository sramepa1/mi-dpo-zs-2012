/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import dpo4mvc.Controller;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import javax.swing.event.TableModelListener;
import javax.swing.table.TableModel;
import ui.IView;


/**
 *
 * @author rusty
 */
public class Model implements INotifiable {
    
    public Model(Controller ctrl) {
        this.shapesByTypes = new HashMap<String, ArrayList<Shape>>();
        this.viewsByTypes = new HashMap<String, ArrayList<IView>>();
    }
    
    private Controller ctrl;
    
    private HashMap<String, ArrayList<Shape>> shapesByTypes;
    
    private HashMap<String, ArrayList<IView>> viewsByTypes;;
    
   
    
    //////////////// Storage logic
    
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
		System.out.println("Boom!");	// TODO for testing purposes only, remove later!
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
    
    //////////////// Listening views
    
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
    
    
    //////////////// ...
    
    public TableAdapter createTableAdapter(String typeName) {
        return new TableAdapter(this, typeName);
    }
    
    
    public class TableAdapter implements TableModel {

        public TableAdapter(Model model, String typeName) {
            this.model = model;
            this.typeName = typeName;
        }

        private Model model;
        private String typeName;
        
        @Override
        public int getRowCount() {
            return model.shapesByTypes.get(typeName).size();
        }

        @Override
        public int getColumnCount() {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public String getColumnName(int i) {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public Class<?> getColumnClass(int i) {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public boolean isCellEditable(int i, int i1) {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public Object getValueAt(int i, int i1) {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public void setValueAt(Object o, int i, int i1) {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public void addTableModelListener(TableModelListener tl) {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public void removeTableModelListener(TableModelListener tl) {
            throw new UnsupportedOperationException("Not supported yet.");
        }

    }
}
