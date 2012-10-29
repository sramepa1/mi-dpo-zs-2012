/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

/**
 *
 * @author pavel
 */
public interface INode {
	
	String evaluate();
	
    void expand(IWalkStrategy strat);
	
}
