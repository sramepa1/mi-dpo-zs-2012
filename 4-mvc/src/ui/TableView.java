package ui;

import java.awt.GridLayout;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.UIManager;

/**
 *
 * @author pavel
 */
public class TableView extends ViewPanel {
	
	public TableView() { // TODO pass model and controller
		setLayout(new GridLayout(0,1));
		setBackground(UIManager.getColor("window"));
		add(new JScrollPane(new JTable(20,4)));
		add(new JScrollPane(new JTable(20,4)));
	}

	@Override
	public void notifyChange() {
		throw new UnsupportedOperationException("Not supported yet.");
	}	
	
}
