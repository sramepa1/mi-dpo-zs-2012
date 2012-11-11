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
public abstract class BinaryOperator implements IExpression
{
	protected IExpression firstOperand;
	protected IExpression secondOperand;

	public BinaryOperator(IExpression firstOperand, IExpression secondOperand)
	{
		setFirstOperand(firstOperand);
		setSecondOperand(secondOperand);
	}
	
	void setFirstOperand(IExpression o)
	{
		firstOperand = o;
	}
    
	void setSecondOperand(IExpression o)
	{
		secondOperand = o;
	}
	
	public IExpression getFirstOperand()
	{
		return firstOperand;
	}
	
	public IExpression getSecondOperand()
	{
		return secondOperand;
	}
	
	public abstract Integer evaluate();
	
	public abstract InOrderIterator inOrderIterator();

	public abstract PostOrderIterator postOrderIterator();

}
