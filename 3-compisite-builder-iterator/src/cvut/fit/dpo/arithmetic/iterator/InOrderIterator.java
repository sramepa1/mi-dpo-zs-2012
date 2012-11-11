package cvut.fit.dpo.arithmetic.iterator;

import cvut.fit.dpo.arithmetic.elements.AddOperation;
import cvut.fit.dpo.arithmetic.elements.CloseBracketOperation;
import java.util.Iterator;

import cvut.fit.dpo.arithmetic.elements.ExpressionElement;
import cvut.fit.dpo.arithmetic.elements.OpenBracketOperation;
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
        
        if(element instanceof AddOperation) {
            buffer.add(new OpenBracketOperation());
            buffer.add(element);  
            buffer.add(new CloseBracketOperation());  
        } else {
            buffer.add(element);  
        }
        
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
		return buffer.peekFirst();
	}

	@Override
	public void remove()
	{
        throw new UnsupportedOperationException("The remove operation is not supported by this Iterator");
	}

}
