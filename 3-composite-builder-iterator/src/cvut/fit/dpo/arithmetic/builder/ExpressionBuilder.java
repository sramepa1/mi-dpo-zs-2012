/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package cvut.fit.dpo.arithmetic.builder;

import cvut.fit.dpo.arithmetic.*;
import java.util.Stack;

/**
 *
 * @author pavel
 */
public class ExpressionBuilder {
	
	protected Stack<ArithmeticExpression> stack;
	
	public ExpressionBuilder() {
		stack = new Stack<ArithmeticExpression>();
	}

	public void pushNumber(int value) {
		stack.push(new NumericOperand(value));
	}
	
	public void add() {
		Crate c = popCrate();
		stack.push(new AddOperator(c.left, c.right));
	}
	
	public void substract() {
		Crate c = popCrate();
		stack.push(new SubstractOperator(c.left, c.right));	
	}
	
	public ArithmeticExpression pop() {
		return stack.pop();
	}
	
	
	
	protected Crate popCrate() {
		Crate crate = new Crate();
		crate.right = stack.pop();
		crate.left = stack.pop();
		return crate;
	}
	
	protected class Crate {		
		public ArithmeticExpression left;
		public ArithmeticExpression right;		
	}
}
