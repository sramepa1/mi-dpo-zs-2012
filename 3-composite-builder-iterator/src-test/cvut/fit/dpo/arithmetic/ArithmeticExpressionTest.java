package cvut.fit.dpo.arithmetic;

import static org.junit.Assert.*;

import java.util.Iterator;

import org.junit.Test;

import cvut.fit.dpo.arithmetic.elements.ExpressionElement;
import cvut.fit.dpo.pr2.ArithmeticExpressionCreator;

public class ArithmeticExpressionTest
{
	/**
	 * I would like not to use getRoot() at all.
	 */
	@Test(expected = UnsupportedOperationException.class)
	public void testGetRoot()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpression1();
		e.getRoot();
	}

	@Test
	public void testGetInOrderIterator()
	{
		// Creates 3 - (1 + 2)
		ArithmeticExpression e = new ArithmeticExpressionCreator().createExpression1();
		Iterator<ExpressionElement> it = e.getInOrderIterator();
		assertNotNull(it);
		
		assertEquals("(", it.next().stringValue());
		assertEquals("3", it.next().stringValue());
		assertEquals("-", it.next().stringValue());
		assertEquals("(", it.next().stringValue());
		assertEquals("1", it.next().stringValue());
		assertEquals("+", it.next().stringValue());
		assertEquals("2", it.next().stringValue());
		assertEquals(")", it.next().stringValue());
		assertEquals(")", it.next().stringValue());
		assertFalse(it.hasNext());
	}

	@Test(expected = UnsupportedOperationException.class)
	public void testGetInOrderIteratorRemove()
	{
		// Creates 3 - (1 + 2)
		ArithmeticExpression e = new ArithmeticExpressionCreator().createExpression1();
		Iterator<ExpressionElement> it = e.getInOrderIterator();
		assertNotNull(it);
		it.remove();
	}

	
	@Test
	public void testGetPostOrderIterator()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator().createExpression1();
		Iterator<ExpressionElement> it = e.getPostOrderIterator();
		assertNotNull(it);

		// Creates 3 - (1 + 2)
		assertEquals("3", it.next().stringValue());
		assertEquals("1", it.next().stringValue());
		assertEquals("2", it.next().stringValue());
		assertEquals("+", it.next().stringValue());
		assertEquals("-", it.next().stringValue());
		assertFalse(it.hasNext());
	}

	@Test(expected = UnsupportedOperationException.class)
	public void testGetPostOrderIteratorRemove()
	{
		// Creates 3 - (1 + 2)
		ArithmeticExpression e = new ArithmeticExpressionCreator().createExpression1();
		Iterator<ExpressionElement> it = e.getPostOrderIterator();
		assertNotNull(it);
		it.remove();
	}
	

}
