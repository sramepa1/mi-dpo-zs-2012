package cvut.fit.dpo.arithmetic;

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
	
	public Object getFirstOperand()
	{
		return firstOperand;
	}
	
	public Object getSecondOperand()
	{
		return secondOperand;
	}
	
	public abstract Integer evaluate();
	/*{
		int val1 = getOperandValue(firstOperand);
		int val2 = getOperandValue(secondOperand);
		
		return evaluate(val1, val2);
	}*/
	
	public InOrderIterator inOrderIterator()
	{
		return null;
	}

	public PostOrderIterator postOrderIterator()
	{
		return null;
	}

}
