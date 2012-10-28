/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

/**
 *
 * @author pavel
 */
public class Leaf implements INode {
	
	protected String value;
	
	public Leaf(String val) {
		value = val;
	}

	@Override
	public String print() {
		return value;
	}
	
}
