/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package cvut.fit.dpo.arithmetic;

import cvut.fit.dpo.arithmetic.iterator.InOrderIterator;
import cvut.fit.dpo.arithmetic.iterator.PostOrderIterator;

/**
 *
 * @author rusty
 */
public interface IExpression {
    Integer evaluate();
    InOrderIterator inOrderIterator();
    PostOrderIterator postOrderIterator();
}
