package cvut.fit.dpo.pr2;

import cvut.fit.dpo.arithmetic.AddOperator;
import cvut.fit.dpo.arithmetic.ArithmeticExpression;
import cvut.fit.dpo.arithmetic.BinaryOperator;
import cvut.fit.dpo.arithmetic.NumericOperand;
import cvut.fit.dpo.arithmetic.SubstractOperator;

/**
 * Printer for {@link ArithmeticExpression}s. It can print
 * 	inOrder notation (3 + 1) or postOrder notation (3 1 +).
 * 
 * PostOrder is RPN (Reverse Polish Notation) in fact. See
 * 	wiki for more information.
 * 
 * @author Jan Kurš
 *
 */
public class ArithmeticExpressionPrinter
{
	private static final String ANY_BINARY_OPERATOR_STRING = "b";
	private static final String SUBSTRACT_OPERATOR_STRING = "-";
	private static final String PLUS_OPERATOR_STRING = "+";

	private ArithmeticExpression expression;

	public ArithmeticExpressionPrinter(ArithmeticExpression expression)
	{
		setExpression(expression);
	}

	private void setExpression(ArithmeticExpression expression)
	{
		this.expression = expression;
	}

	/**
	 * Print an expression in classical notation, e.g. (3+1).
	 * 
	 * The "(" and ")" is used to preserve priorities.
	 * 
	 * @return String in classical "inOrder" format.
	 */
	public String printInOrder()
	{
		// Remember, do not use the getRoot() method!
		// The iterator may help :)
		BinaryOperator root = expression.getRoot();
		String operator = binaryOperatorToString(root);

		String lString = printInOrder(root.getFirstOperand());
		String rString = printInOrder(root.getSecondOperand());

		return "(" + lString + operator + rString + ")";
	}

	private String printInOrder(Object o)
	{
		if (o instanceof NumericOperand)
		{
			return printInOrder((NumericOperand) o);
		}

		if (o instanceof BinaryOperator)
		{
			return printInOrder((BinaryOperator) o);
		}

		throw new IllegalArgumentException("Unknown argument");
	}

	private String printInOrder(NumericOperand o)
	{
		return o.getValue().toString();
	}

	private String printInOrder(BinaryOperator o)
	{
		return "(" + printInOrder(o.getFirstOperand())
				+ binaryOperatorToString(o)
				+ printInOrder(o.getSecondOperand()) + ")";
	}

	private String binaryOperatorToString(BinaryOperator o)
	{
		if (o instanceof AddOperator)
		{
			return PLUS_OPERATOR_STRING;
		}

		if (o instanceof SubstractOperator)
		{
			return SUBSTRACT_OPERATOR_STRING;
		}

		return ANY_BINARY_OPERATOR_STRING;
	}

	/**
	 * Print an expression in RPN notation, e.g. 3 1 +.
	 *
	 * Please note, the "(" and ")" is no longer necessary, because
	 * 	RPN does not need them :)
	 * 
	 * @return string in "postOrder" (RPN) format.
	 */
	public String printPostOrder()
	{
		// Remember, do not use the getRoot() method!
		// The iterator may help :)
		
		BinaryOperator root = expression.getRoot();
		String operator = binaryOperatorToString(root);

		String lString = printPostOrder(root.getFirstOperand());
		String rString = printPostOrder(root.getSecondOperand());

		return lString + " " + rString + " " + operator;
	}

	private String printPostOrder(Object o)
	{
		if (o instanceof NumericOperand)
		{
			return printPostOrder((NumericOperand) o);
		}

		if (o instanceof BinaryOperator)
		{
			return printPostOrder((BinaryOperator) o);
		}

		throw new IllegalArgumentException("Unknown argument");
	}

	private String printPostOrder(NumericOperand o)
	{
		return o.getValue().toString();
	}

	private String printPostOrder(BinaryOperator o)
	{
		return printPostOrder(o.getFirstOperand()) + " "
				+ printPostOrder(o.getSecondOperand()) + " "
				+ binaryOperatorToString(o);
	}
}
