package cvut.fit.dpo.arithmetic;

import cvut.fit.dpo.arithmetic.iterator.InOrderIterator;
import cvut.fit.dpo.arithmetic.iterator.PostOrderIterator;

/**
 * Represents the Binary operations like + - etc.
 * 
 * @author Jan Kurš
 *
 */
public abstract class BinaryOperator
{
	private Object firstOperand;
	private Object secondOperand;

	protected abstract Integer evaluate(Integer val1, Integer val2);
	
	public BinaryOperator(Object firstOperand, Object secondOperand)
	{
		setFirstOperand(firstOperand);
		setSecondOperand(secondOperand);
	}
	
	void setFirstOperand(Object o)
	{
		firstOperand = o;
	}
	void setSecondOperand(Object o)
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
	
	public Integer evaluate()
	{
		int val1 = getOperandValue(firstOperand);
		int val2 = getOperandValue(secondOperand);
		
		return evaluate(val1, val2);
	}
	
	public InOrderIterator inOrderIterator()
	{
		return null;
	}

	public PostOrderIterator postOrderIterator()
	{
		return null;
	}
	
	
	private Integer getOperandValue(Object o)
	{
		if (o instanceof NumericOperand)
		{
			return ((NumericOperand)o).getValue();
		}
		
		if (o instanceof BinaryOperator)
		{
			return ((BinaryOperator)o).evaluate();
		}
		
		throw new IllegalArgumentException("Unsuported operand type!");
	}

	
}
