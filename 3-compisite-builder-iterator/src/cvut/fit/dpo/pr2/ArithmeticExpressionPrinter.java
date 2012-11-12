package cvut.fit.dpo.pr2;

import cvut.fit.dpo.arithmetic.ArithmeticExpression;
import cvut.fit.dpo.arithmetic.elements.ExpressionElement;
import java.util.Iterator;

/**
 * Printer for {@link ArithmeticExpression}s. It can print
 * 	inOrder notation (3 + 1) or postOrder notation (3 1 +).
 * 
 * PostOrder is RPN (Reverse Polish Notation) in fact. See
 * 	wiki for more information.
 * 
 * @author Jan Kurš
 *
 */
public class ArithmeticExpressionPrinter
{
	private ArithmeticExpression expression;

	public ArithmeticExpressionPrinter(ArithmeticExpression expression)
	{
		setExpression(expression);
	}

	private void setExpression(ArithmeticExpression expression)
	{
		this.expression = expression;
	}


    private String print(Iterator<ExpressionElement> it) {
		StringBuilder sb = new StringBuilder();		
		while(it.hasNext()) {
			sb.append(it.next().stringValue());
		}
        
		return sb.toString();
	}
    
	private String print(Iterator<ExpressionElement> it, char delimiter) {
		StringBuilder sb = new StringBuilder();		

		while(it.hasNext()) {
			sb.append(it.next().stringValue());
            sb.append(delimiter);
		}
        
        sb.delete(sb.length() - 1, sb.length());
        
		return sb.toString();
	}
	
	/**
	 * Print an expression in classical notation, e.g. (3+1).
	 * 
	 * The "(" and ")" is used to preserve priorities.
	 * 
	 * @return String in classical "inOrder" format.
	 */
	public String printInOrder()
	{
		return print(expression.getInOrderIterator());
	}
	
	/**
	 * Print an expression in RPN notation, e.g. 3 1 +.
	 *
	 * Please note, the "(" and ")" is no longer necessary, because
	 * 	RPN does not need them :)
	 * 
	 * @return string in "postOrder" (RPN) format.
	 */
	public String printPostOrder()
	{
		return print(expression.getPostOrderIterator(), ' ');
	}
}
