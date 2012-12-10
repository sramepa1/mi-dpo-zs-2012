package ui;

import java.awt.GridLayout;
import javax.swing.JPanel;
import javax.swing.UIManager;
import model.Model;

/**
 *
 * @author pavel
 */
public class TableViewPanel extends JPanel {
	
	
	public TableViewPanel(Model model) {
		
		setLayout(new GridLayout(0,1));
		setBackground(UIManager.getColor("window"));
		
		for (String shapeType : model.getShapeTypes()) {
			TableView tableView = new TableView(model, shapeType);
			add(tableView);
			model.addViewByType(shapeType, tableView);
		}
	}
}
