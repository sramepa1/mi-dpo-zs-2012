package cvut.fit.dpo.arithmetic;

import cvut.fit.dpo.arithmetic.elements.AddOperation;
import cvut.fit.dpo.arithmetic.iterator.InOrderIterator;
import cvut.fit.dpo.arithmetic.iterator.PostOrderIterator;

/**
 * Represents the Binary operations like + - etc.
 * 
 * @author Jan Kurš
 *
 */
public abstract class BinaryOperator extends ArithmeticExpression
{
	protected ArithmeticExpression firstOperand;
	protected ArithmeticExpression secondOperand;

	public BinaryOperator(ArithmeticExpression firstOperand, ArithmeticExpression secondOperand)
	{
		setFirstOperand(firstOperand);
		setSecondOperand(secondOperand);
	}
	
	void setFirstOperand(ArithmeticExpression o)
	{
		firstOperand = o;
	}
    
	void setSecondOperand(ArithmeticExpression o)
	{
		secondOperand = o;
	}
	
	public ArithmeticExpression getFirstOperand()
	{
		return firstOperand;
	}
	
	public ArithmeticExpression getSecondOperand()
	{
		return secondOperand;
	}	

}
