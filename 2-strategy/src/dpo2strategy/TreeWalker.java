/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

/**
 *
 * @author pavel
 */
public class TreeWalker {
	
	private IWalkStrategy strat;
	
	public TreeWalker(IWalkStrategy strategy) {
		setStrategy(strategy);
	}
	
	public final void setStrategy(IWalkStrategy strategy) {
		strat = strategy;
	}
	
	public void traverse(INode treeRoot) {
		strat.insert(treeRoot);		
		while(strat.hasSomewhereToGo()) {
			expand(strat.next());
		}
	}
	
	private void expand(INode node) {
        node.expand(strat);
		System.out.println(node.evaluate());
	}
    
}
