/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package cvut.fit.dpo.arithmetic.builder;

import cvut.fit.dpo.arithmetic.ArithmeticExpression;
import java.util.EmptyStackException;
import java.util.Scanner;

/**
 *
 * @author pavel
 */
public class RPNBuilder {
	
	protected final String OperatorRegex = "[+-]";

	public ArithmeticExpression createExpressionFromRPN(String input) {
		ArithmeticExpression result = null;
		
		try {
			ExpressionBuilder b = new ExpressionBuilder();
			Scanner sc = new Scanner(input);
			while(sc.hasNext()) {

				if(sc.hasNextInt()) {
					b.pushNumber(sc.nextInt());
				} else if(sc.hasNext(OperatorRegex)) {
					char c = sc.next(OperatorRegex).charAt(0);
					switch(c) {
						case '+':	b.add(); break;
						case '-':	b.substract(); break;
					}
				} else {
					throw new IllegalArgumentException("Invalid token at: " + sc.nextLine());
				}
				sc.skip("\\s*");
			}
			result = b.pop();
					
		} catch(EmptyStackException ex) {
			throw new IllegalArgumentException("Invalid RPN.", ex);
		}
		
		return result;
	}
	
}
