/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dpo2strategy;

/**
 *
 * @author pavel
 */
public class InnerNode implements INode {
	
	protected INode left = new NullNode();
	protected INode middle = new NullNode();
	protected INode right = new NullNode();

	public INode getLeft() {
		return left;
	}

	public void setLeft(INode left) {
		this.left = left;
	}	
	
	public INode getMiddle() {
		return middle;
	}

	public void setMiddle(INode middle) {
		this.middle = middle;
	}
	
	public INode getRight() {
		return right;
	}

	public void setRight(INode right) {
		this.right = right;
	}

	@Override
	public String print() {
		// TODO
		return ".";
	}

}
