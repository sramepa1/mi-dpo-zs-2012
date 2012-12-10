package cvut.fit.dpo.arithmetic.iterator;

import cvut.fit.dpo.arithmetic.elements.AddOperation;
import cvut.fit.dpo.arithmetic.elements.CloseBracketOperation;
import java.util.Iterator;

import cvut.fit.dpo.arithmetic.elements.ExpressionBinaryElement;
import cvut.fit.dpo.arithmetic.elements.ExpressionElement;
import cvut.fit.dpo.arithmetic.elements.OpenBracketOperation;
import cvut.fit.dpo.arithmetic.elements.SubstractOperation;
import java.util.LinkedList;

public class InOrderIterator implements Iterator<ExpressionElement>
{
    
    private LinkedList<ExpressionElement> buffer;
    
    public InOrderIterator(ExpressionElement element) {
        buffer = new LinkedList<ExpressionElement>();
        buffer.add(element);
    }
    
    public InOrderIterator(InOrderIterator a, InOrderIterator b, ExpressionElement element) {
    	addElement(a, b, element);
    }
    
    public InOrderIterator(InOrderIterator a, InOrderIterator b, ExpressionBinaryElement element) {
    	addElement(a, b, element);
        buffer.addFirst(new OpenBracketOperation());
        buffer.addLast(new CloseBracketOperation());
    }
    
    private void addElement(InOrderIterator a, InOrderIterator b, ExpressionElement element) {
    	buffer = a.buffer;
        buffer.add(element);  
        buffer.addAll(b.buffer);
    }
    
	@Override
	public boolean hasNext()
	{
		return buffer.size() != 0;
	}

	@Override
	public ExpressionElement next()
	{
		return buffer.removeFirst();
	}

	@Override
	public void remove()
	{
        throw new UnsupportedOperationException("The remove operation is not supported by this Iterator");
	}

}
