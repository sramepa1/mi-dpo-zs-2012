package cvut.fit.dpo.arithmetic;

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

}
