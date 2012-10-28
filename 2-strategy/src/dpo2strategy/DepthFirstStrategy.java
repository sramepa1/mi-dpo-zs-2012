/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

import java.util.Stack;

/**
 *
 * @author pavel
 */
public class DepthFirstStrategy implements IWalkStrategy {
	
	private Stack<INode> stack = new Stack<INode>();

	@Override
	public INode next() {
		return stack.pop();
	}

	@Override
	public void insert(INode node) {
		stack.push(node);
	}

	@Override
	public boolean hasSomewhereToGo() {
		return !stack.empty();
	}
	
}
