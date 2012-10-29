/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author pavel
 */
public class Leaf implements INode {
	
	protected int value;
    private final static String MESSAGE = "I found a cone! Pitty I am not a squirell.\n  Neverthless I was forced to stop for few moments and wander about it's beauty.";
	
	public Leaf() {
		value = (int) (Math.random() * 5);
	}

	@Override
	public String evaluate() {
        
        try {
            Thread.sleep(value * 1000);
        } catch (InterruptedException ex) {
            //no action needed
        }
        
		return MESSAGE;
	}

    @Override
    public void expand(IWalkStrategy strat) {}
	
}

    