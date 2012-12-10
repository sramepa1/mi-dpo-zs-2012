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
		table = new JTable(model.createTableAdapter(type));
		setViewportView(table);
	}

	@Override
	public void notifyChange() {
		table.revalidate();
	}
}
