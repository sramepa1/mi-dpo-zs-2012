/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

/**
 *
 * @author pavel
 */
public class StrategyFactory {
	
	public IWalkStrategy createStrategy(String name) throws IllegalArgumentException {
		if(name.equals("bfs")) {
			return new BreadthFirstStrategy();
		} else if (name.equals("dfs")) {
			return new DepthFirstStrategy();
		} else {
			throw new IllegalArgumentException(name + " is not a valid strategy name.");
		}
	}
	
}
