package cvut.fit.dpo.arithmetic.iterator;

import cvut.fit.dpo.arithmetic.elements.AddOperation;
import cvut.fit.dpo.arithmetic.elements.CloseBracketOperation;
import java.util.Iterator;

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
        buffer = a.buffer;
        buffer.add(element);  
        buffer.addAll(b.buffer);
        
        if(element instanceof AddOperation || element instanceof SubstractOperation) { //TODO better
            buffer.addFirst(new OpenBracketOperation());
            buffer.addLast(new CloseBracketOperation());
        }
    }
    
	@Override
	public boolean hasNext()
	{
		return buffer.size() != 0;
	}

	@Override
	public ExpressionElement next()
	{
		//return buffer.peekFirst();
		return buffer.removeFirst(); // prevention of infinite while(hasNext()){next()} loops
									// TODO possibly replace with delegate LinkedList Iterator?
	}

	@Override
	public void remove()
	{
        throw new UnsupportedOperationException("The remove operation is not supported by this Iterator");
	}

}
