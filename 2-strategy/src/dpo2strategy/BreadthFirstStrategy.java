/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author pavel
 */
public class BreadthFirstStrategy implements IWalkStrategy {
	
	private Queue<INode> queue = new LinkedList<INode>();

	@Override
	public INode next() {
		return queue.remove();
	}

	@Override
	public void insert(INode node) {
		queue.add(node);
	}

	@Override
	public boolean hasSomewhereToGo() {
		return !queue.isEmpty();
	}
	
}
