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
		stack.push(new AddOperator(stack.pop(), stack.pop()));
	}
	
	public void substract() {
		ArithmeticExpression right = stack.pop();
		ArithmeticExpression left = stack.pop();
		stack.push(new SubstractOperator(left, right));		
	}
	
	public ArithmeticExpression pop() {
		return stack.pop();
	}
}
