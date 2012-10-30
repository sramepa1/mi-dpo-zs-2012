package cvut.fit.dpo.arithmetic;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

public class AddOperatorTest
{
	NumericOperand o1;
	NumericOperand o2;
	
	@Before
	public void setUp(){
		o1 = new NumericOperand(1);
		o2 = new NumericOperand(2);
	}
	
	@Test
	public void testGetFirstOperand()
	{
		AddOperator o = new AddOperator(o1, o2);
		assertEquals(o1, o.getFirstOperand());
	}

	@Test
	public void testGetSecondOperand()
	{
		AddOperator o = new AddOperator(o1, o2);
		assertEquals(o2, o.getSecondOperand());
	}

}
