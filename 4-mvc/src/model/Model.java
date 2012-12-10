/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import dpo4mvc.Controller;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import javax.swing.event.TableModelListener;
import javax.swing.table.AbstractTableModel;
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
        this.allViews = new HashSet<IView>();
        this.shapesPrototypes = new HashMap<String, Shape>();
    }
    
    private Controller ctrl;
    
    private HashMap<String, Shape> shapesPrototypes;
    private HashMap<String, ArrayList<Shape>> shapesByTypes;
    
    private HashMap<String, ArrayList<IView>> viewsByTypes;;
    private HashSet<IView> allViews;
    
    
    //////////////// Storage logic
    
    public void registerPrototype(Shape prototype) {
        if(shapesPrototypes.containsKey(prototype.getTypeName())) {
            throw new IllegalArgumentException("This type of shapes already exists.");
        }
        
        shapesByTypes.put(prototype.getTypeName(), new ArrayList<Shape>());
        shapesPrototypes.put(prototype.getTypeName(), prototype);
    }
    
    public int addShape(Shape shape) {
        if(!shapesByTypes.containsKey(shape.getTypeName())) {
            throw new IllegalArgumentException("Unknown shape type.");
        }
        
        ArrayList<Shape> shapeStorage = shapesByTypes.get(shape.getTypeName());
        shapeStorage.add(shape);
        
        shape.addListener(this);
        reportChange(shape);
        
        return shapeStorage.size() - 1;
    }
    
    public void clearAll() {
        for (Map.Entry<String, ArrayList<Shape>> entry : shapesByTypes.entrySet())
        {
            entry.setValue(new ArrayList<Shape>());
        }
		reportChange();
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
    
    public Iterable<Shape> getAllShapes() {
        
        ArrayList<Shape> myclone = new ArrayList<Shape>();
        
        for (Map.Entry<String, ArrayList<Shape>> entry : shapesByTypes.entrySet())
        {
            myclone.addAll( (ArrayList<Shape>) entry.getValue().clone());
        }
        
        return myclone;
    }
    
    //////////////// Listening views
    
    public void addView(IView view) {
        for (Map.Entry<String, ArrayList<Shape>> entry : shapesByTypes.entrySet())
        {
            addViewByType(entry.getKey(), view);
        }
        
        allViews.add(view);
    }
    
    public void addViewByType(String typeName, IView view) {
        ArrayList<IView> listeningViews = viewsByTypes.get(typeName);
        
        if(listeningViews == null) {
            listeningViews = new ArrayList<IView>();
            viewsByTypes.put(typeName, listeningViews);
        }
        
        listeningViews.add(view);
        allViews.add(view);
    }

    @Override
    public void reportChange(Shape changedObj) {
        
        ArrayList<IView> listeningViews = viewsByTypes.get(changedObj.getTypeName());
        
        for(IView view : listeningViews) {
            view.notifyChange();
        }
    }
    
    public void reportChange() {
        for(IView view : allViews) {
            view.notifyChange();
        }
    }
    
    
    //////////////// ...
    
    public TableAdapter createTableAdapter(String typeName) {
        return new TableAdapter(this, typeName);
    }
    
    
    public class TableAdapter extends AbstractTableModel implements IView {

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
            return model.shapesPrototypes.get(typeName).getAttributeNames().length;
        }

        @Override
        public String getColumnName(int i) {
            return model.shapesPrototypes.get(typeName).getAttributeNames()[i];
        }

        @Override
        public Class<?> getColumnClass(int i) {
            return Integer.class;
        }

        @Override
        public boolean isCellEditable(int i, int i1) {
            return true;
        }

        @Override
        public Object getValueAt(int i, int i1) {
            return model.getShape(typeName, i).getAttribute(model.shapesPrototypes.get(typeName).getAttributeNames()[i1]);
        }

        @Override
        public void setValueAt(Object o, int i, int i1) {
            model.getShape(typeName, i).setAttribute(model.shapesPrototypes.get(typeName).getAttributeNames()[i1], ((Integer) o).intValue() );
        }

		@Override
		public void notifyChange() {
			fireTableDataChanged();
		}

    }
}
