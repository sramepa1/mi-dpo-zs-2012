package cvut.fit.dpo.arithmetic;

import cvut.fit.dpo.arithmetic.elements.AddOperation;
import cvut.fit.dpo.arithmetic.iterator.InOrderIterator;
import cvut.fit.dpo.arithmetic.iterator.PostOrderIterator;

/**
 * Represents + operation
 * 
 * @author Jan Kurš
 * 
 */
public class AddOperator extends BinaryOperator
{

	public AddOperator(IExpression firstOperand, IExpression secondOperand)
	{
		super(firstOperand, secondOperand);
	}

	@Override
	public Integer evaluate()
	{
		return firstOperand.evaluate() + secondOperand.evaluate();
	}
    
    public InOrderIterator inOrderIterator()
	{
		return new InOrderIterator(firstOperand.inOrderIterator(), secondOperand.inOrderIterator(), new AddOperation());
	}

	public PostOrderIterator postOrderIterator()
	{
		return null;
	}

}
