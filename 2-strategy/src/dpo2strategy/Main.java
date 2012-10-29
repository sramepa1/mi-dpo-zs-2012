package dpo2strategy;

public class Main {

	public static void main(String[] args) {
		if(args.length != 1) {
			incorrectUsage("You supplied " + args.length + " arguments.");			
		}
		try {
			StrategyFactory factory = new StrategyFactory();
			IWalkStrategy strat = factory.createStrategy(args[0]);
			TreeWalker walker = new TreeWalker(strat);
			walker.traverse(createTree());
			
		} catch(IllegalArgumentException e) {
			incorrectUsage(e.getMessage());
		}
	}
	
	private static INode createTree() {
		// TODO better tree
		InnerNode root = new InnerNode();
		root.setLeft(new Leaf("A"));
		root.setRight(new Leaf("B"));
		return root;
	}
	
	private static void	incorrectUsage(String msg) {
		System.err.println("This requires exactly one argument naming a strategy.");
		System.err.println(msg);
		System.exit(1);
	}
	
}

