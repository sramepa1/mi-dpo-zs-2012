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
	
	protected int value;
    protected String art;
    private final static String MESSAGE = "I found a cone! Pity I am not a squirrel. Nevertheless I was forced to stop for a few moments and wonder about its beauty.";
	
    
	public Leaf(String art) {
		value = (int) ((Math.random() * 0.8 + 1.2) * 1000);
        this.art = art;
	}

	@Override
	public String evaluate() {
        
        try {
            Thread.sleep(value );
        } catch (InterruptedException ex) {
            //no action needed
        }
        
		return art + MESSAGE;
	}

    @Override
    public void expand(IWalkStrategy strat) {}
	
}

    