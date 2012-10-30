package cvut.fit.dpo.pr2;

import static org.junit.Assert.*;

import org.junit.Test;

import cvut.fit.dpo.arithmetic.ArithmeticExpression;

public class ArithmeticExpressionPrinterTest
{

	@Test
	public void testPrintInOrder1()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpression1();
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("(3-(1+2))", p.printInOrder());
	}

	@Test
	public void testPrintInOrder2()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpression2();
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("((3-1)+2)", p.printInOrder());
	}

	@Test
	public void testPrintInOrder3()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpressionFromRPN("1 2 + 3 4 + -");
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("((1+2)-(3+4))", p.printInOrder());
	}
	
	@Test
	public void testPrintInOrder4()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpressionFromRPN("1");
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("1", p.printInOrder());
	}

	@Test
	public void testPrintPostOrder1()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpression1();
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("3 1 2 + -", p.printPostOrder());
	}

	@Test
	public void testPrintPostOrder2()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpression2();
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("3 1 - 2 +", p.printPostOrder());
	}
	
	@Test
	public void testPrintPostOrder3()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpressionFromRPN("1 2 + 3 4 + -");
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("1 2 + 3 4 + -", p.printPostOrder());
	}

	@Test
	public void testPrintPostOrder4()
	{
		ArithmeticExpression e = new ArithmeticExpressionCreator()
				.createExpressionFromRPN("1");
		ArithmeticExpressionPrinter p = new ArithmeticExpressionPrinter(e);
		
		assertEquals("1", p.printInOrder());
	}
	
}
