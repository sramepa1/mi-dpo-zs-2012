package cvut.fit.dpo.arithmetic;

/**
 * Represents + operation
 * 
 * @author Jan Kurš
 * 
 */
public class AddOperator extends BinaryOperator
{

	public AddOperator(Object firstOperand, Object secondOperand)
	{
		super(firstOperand, secondOperand);
	}

	@Override
	protected Integer evaluate(Integer val1, Integer val2)
	{
		return val1 + val2;
	}

}
