package ui;

import javax.swing.JScrollPane;
import javax.swing.JTable;
import model.Model;

/**
 *
 * @author pavel
 */
public class TableView extends JScrollPane implements IView {
	
	JTable table;
	
	public TableView(Model model, String type) {		
		table = new JTable(model.createTableAdapter(type)); // TODO enable when adapter is ready
		//table = new JTable(3,3);
		setViewportView(table);
	}

	@Override
	public void notifyChange() {
		table.revalidate();
	}
}
