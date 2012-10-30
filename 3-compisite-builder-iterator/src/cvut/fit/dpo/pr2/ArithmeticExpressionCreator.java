package cvut.fit.dpo.pr2;

import cvut.fit.dpo.arithmetic.AddOperator;
import cvut.fit.dpo.arithmetic.ArithmeticExpression;
import cvut.fit.dpo.arithmetic.BinaryOperator;
import cvut.fit.dpo.arithmetic.NumericOperand;
import cvut.fit.dpo.arithmetic.SubstractOperator;


/**
 * Stupid class which can create some {@link ArithmeticExpression}s.
 * 
 * @author Jan Kurš
 *
 */
public class ArithmeticExpressionCreator
{
	/**
	 * Creates 3 - (1 + 2)
	 * 
	 * This is ugly. I don't like creating expressions in this
	 * 	form. I never know, what expression I have created...
	 */
	public ArithmeticExpression createExpression1()
	{
		ArithmeticExpression e = new ArithmeticExpression();
		
		NumericOperand op1 = new NumericOperand(1);
		NumericOperand op2 = new NumericOperand(2);
		NumericOperand op3 = new NumericOperand(3);
		
		BinaryOperator o2 = new AddOperator(op1, op2);
		BinaryOperator o1 = new SubstractOperator(op3, o2);
		
		e.setRoot(o1);
		return e;
	}

	/**
	 * Creates (3 - 1) + 2
	 *
	 * This is ugly. I don't like creating expressions in this
	 * 	form. I never know, what expression I have created...
	 */
	public ArithmeticExpression createExpression2()
	{
		ArithmeticExpression e = new ArithmeticExpression();
		
		NumericOperand op1 = new NumericOperand(1);
		NumericOperand op2 = new NumericOperand(2);
		NumericOperand op3 = new NumericOperand(3);
		
		BinaryOperator o1 = new SubstractOperator(op3, op1);
		BinaryOperator o2 = new AddOperator(o1, op2);
		
		e.setRoot(o2);
		return e;
	}
	
	/**
	 * Creates any expression from the RPN input. This is nice and
	 * 	universal. 
	 * 
	 * @see http://en.wikipedia.org/wiki/Reverse_Polish_notation
	 * 	
	 * @param input in Reverse Polish Notation
	 * @return {@link ArithmeticExpression} equivalent to the RPN input.
	 */
	public ArithmeticExpression createExpressionFromRPN(String input)
	{
		// Good entry point for Builder :)
		throw new UnsupportedOperationException("Don't know how to do it :(");
	}
}
