package ui;

import java.awt.Color;
import java.awt.Dimension;
import javax.swing.BorderFactory;

/**
 *
 * @author pavel
 */
public class GraphicView extends ViewPanel {
	
	public GraphicView() { // TODO pass model and controller
		super(true);
		setMinimumSize(new Dimension(160, 160));
		setBackground(Color.WHITE);
		setBorder(BorderFactory.createLineBorder(Color.black, 2));
	}

	@Override
	public void notifyChange() {
		throw new UnsupportedOperationException("Not supported yet.");
	}
	
}
