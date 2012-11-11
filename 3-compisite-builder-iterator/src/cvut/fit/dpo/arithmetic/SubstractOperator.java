package cvut.fit.dpo.arithmetic;

import cvut.fit.dpo.arithmetic.elements.SubstractOperation;
import cvut.fit.dpo.arithmetic.iterator.InOrderIterator;
import cvut.fit.dpo.arithmetic.iterator.PostOrderIterator;

/**
 * Represents - operation
 * 
 * @author Jan Kurš
 */
public class SubstractOperator extends BinaryOperator
{

	public SubstractOperator(IExpression firstOperand, IExpression secondOperand)
	{
		super(firstOperand, secondOperand);
	}

	@Override
	public Integer evaluate()
	{
		return firstOperand.evaluate() - secondOperand.evaluate();
	}
    
    public InOrderIterator inOrderIterator()
	{
		return new InOrderIterator(firstOperand.inOrderIterator(), secondOperand.inOrderIterator(), new SubstractOperation());
	}

	public PostOrderIterator postOrderIterator()
	{
		return null;
	}

}
