package cvut.fit.dpo.pr2;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class ArithmeticExpressionCreatorTest
{

	@Test
	public void testCreateExpression1()
	{
		ArithmeticExpressionCreator aec = new ArithmeticExpressionCreator();
		assertEquals(new Integer(0), aec.createExpression1().evaluate());
	}

	@Test
	public void testCreateExpression2()
	{
		ArithmeticExpressionCreator aec = new ArithmeticExpressionCreator();
		assertEquals(new Integer(4), aec.createExpression2().evaluate());
	}
	
	@Test
	public void testCreateExpressionFromRPN1()
	{
		ArithmeticExpressionCreator aec = new ArithmeticExpressionCreator();
		assertEquals(new Integer(4), aec.createExpressionFromRPN("3 1 +")
				.evaluate());		

		assertEquals(new Integer(0), aec.createExpressionFromRPN("3 1 2 + -")
				.evaluate());		
		
		assertEquals(new Integer(0), aec.createExpressionFromRPN("1 2 3 - +")
				.evaluate());		

		assertEquals(new Integer(-2), aec.createExpressionFromRPN("3 1 + 4 - 2 -")
				.evaluate());		
	}

	@Test
	public void testCreateExpressionFromRPN2()
	{
		ArithmeticExpressionCreator aec = new ArithmeticExpressionCreator();
		assertEquals(new Integer(1), aec.createExpressionFromRPN("1")
				.evaluate());		
	}

	@Test(expected=IllegalArgumentException.class)
	public void testCreateExpressionFromRPN3()
	{
		ArithmeticExpressionCreator aec = new ArithmeticExpressionCreator();
		assertEquals(new Integer(1), aec.createExpressionFromRPN("1 2 Baf")
				.evaluate());		
	}

	/**
	 * Empty expression is not valid expression
	 */
	@Test(expected=IllegalArgumentException.class)
	public void testCreateExpressionFromRPN4()
	{
		ArithmeticExpressionCreator aec = new ArithmeticExpressionCreator();
		assertEquals(new Integer(1), aec.createExpressionFromRPN("")
				.evaluate());		
	}
	
	
}
