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

	public SubstractOperator(ArithmeticExpression firstOperand, ArithmeticExpression secondOperand)
	{
		super(firstOperand, secondOperand);
	}

	@Override
	public Integer evaluate()
	{
		return firstOperand.evaluate() - secondOperand.evaluate();
	}
    
    public InOrderIterator getInOrderIterator()
	{
		return new InOrderIterator(	(InOrderIterator) firstOperand.getInOrderIterator(),
									(InOrderIterator) secondOperand.getInOrderIterator(),
									new SubstractOperation());
	}

	public PostOrderIterator getPostOrderIterator()
	{
		return new PostOrderIterator( (PostOrderIterator) firstOperand.getPostOrderIterator(),
									  (PostOrderIterator) secondOperand.getPostOrderIterator(),
                                      new SubstractOperation());
	}

}
