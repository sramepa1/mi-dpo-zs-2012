/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

/**
 *
 * @author pavel
 */
public interface IWalkStrategy {
	
	public INode next();
	
	public void insert(INode node);
	
	public boolean hasSomewhereToGo();
}
