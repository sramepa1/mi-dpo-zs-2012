package cvut.fit.dpo.arithmetic;

import java.util.Iterator;

import cvut.fit.dpo.arithmetic.elements.ExpressionElement;

public abstract class ArithmeticExpression
{
	
	/**
	 * {@link #root} field setter.
	 * 
	 * @deprecated Do not provide access to the inner representation
	 */
	public void setRoot(BinaryOperator root)
	{
		throw new UnsupportedOperationException("You shall not pass!!!");
	}

	/**
	 * {@link #root} field getter.
	 * 
	 * @deprecated Do not provide access to the inner representation
	 */
	public BinaryOperator getRoot()
	{
		throw new UnsupportedOperationException("You shall not pass!!!");
	}
	
	public abstract Integer evaluate();
	
	/**
	 * Should be implemented.
	 * 
	 * @return
	 */
	public abstract Iterator<ExpressionElement> getInOrderIterator();

	/**
	 * Should be implemented
	 * 
	 * @return
	 */
	public abstract Iterator<ExpressionElement> getPostOrderIterator();

}
