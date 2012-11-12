package cvut.fit.dpo.arithmetic;

import cvut.fit.dpo.arithmetic.elements.Number;

import cvut.fit.dpo.arithmetic.iterator.InOrderIterator;
import cvut.fit.dpo.arithmetic.iterator.PostOrderIterator;


/**
 * Represents number in the arithmetic expression
 * 
 * @author Jan Kurš
 */
public class NumericOperand extends ArithmeticExpression {
    
	private Integer value;
	
	public NumericOperand(Integer value)
	{
		setValue(value);
	}
	
	public Integer evaluate()
	{
		return value;
	}
	
	public void setValue(Integer value)
	{
		this.value = value;
	}
	
	public InOrderIterator getInOrderIterator()
	{
		return new InOrderIterator(new Number(value));
	}

	public PostOrderIterator getPostOrderIterator()
	{
		return new PostOrderIterator(new Number(value));
	}
	
}
