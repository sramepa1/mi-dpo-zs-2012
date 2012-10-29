/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

/**
 *
 * @author pavel
 */
public class NullNode implements INode {

    private final String MESSAGE = "Oh no. This twig is empty.";
    
	@Override
	public String evaluate() {
		return MESSAGE;
	}

    @Override
    public void expand(IWalkStrategy strat) {}
	
}

