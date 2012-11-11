package cvut.fit.dpo.arithmetic.iterator;

import cvut.fit.dpo.arithmetic.elements.CloseBracketOperation;
import java.util.Iterator;

import cvut.fit.dpo.arithmetic.elements.ExpressionElement;
import cvut.fit.dpo.arithmetic.elements.OpenBracketOperation;
import java.util.LinkedList;

public class PostOrderIterator implements Iterator<ExpressionElement>
{

    private LinkedList<ExpressionElement> buffer;
    
    public PostOrderIterator(ExpressionElement element) {
        buffer = new LinkedList<ExpressionElement>();
        buffer.add(element);
    }
    
    public PostOrderIterator(PostOrderIterator a, PostOrderIterator b, ExpressionElement element) {
        buffer = a.buffer;
        buffer.addAll(b.buffer);
        
        buffer.add(element);  
    }
    
    public PostOrderIterator(PostOrderIterator a) {
        buffer = a.buffer;
        buffer.addFirst(new OpenBracketOperation());
        buffer.addLast(new CloseBracketOperation());
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
