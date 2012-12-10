package dpo4mvc;

import model.Model;

/**
 *
 * @author pavel
 */
public class Controller {
	
	protected Model model;
	
	public void setModel(Model model) {
		this.model = model;
	}
	
	
	public void nuke() {
		model.clearAll();
	}
	
}
