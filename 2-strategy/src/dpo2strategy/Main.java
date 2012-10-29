package dpo2strategy;

public class Main {
    
    private final static String ROOT_MESSAGE = "What a beatifull tree! Let's fid ourselves some cones.";
    private final static String BRANCH1_MESSAGE = "A new branch leading from a mighty trunk. Lucky I am not afraid of heights.";
    private final static String BRANCH2_MESSAGE = "Wonderfull view from here! Let's try to get a little higher.";
    private final static String BRANCH3_MESSAGE = "Wow. There is a huge branch heading right. I am curious what is there.";
    
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
		InnerNode root = new InnerNode(ROOT_MESSAGE, "| ");
        InnerNode branchMiddle1 = new InnerNode(BRANCH1_MESSAGE, "-| ");
        InnerNode branchMiddle2 = new InnerNode(BRANCH2_MESSAGE, "--| ");
        InnerNode branchRight1 = new InnerNode(BRANCH3_MESSAGE, "---/ ");
        
        root.setLeft(new Leaf("-\\\\ "));
        root.setMiddle(branchMiddle1);
		root.setRight(new Leaf("-// "));
        
        branchMiddle1.setLeft(new Leaf("--\\\\ "));
        branchMiddle1.setMiddle(branchMiddle2);
        
        branchMiddle2.setMiddle(new Leaf("---|| "));
        branchMiddle2.setRight(branchRight1);
        
        branchRight1.setLeft(new Leaf("----\\\\ "));
        branchRight1.setMiddle(new Leaf("----|| "));
        branchMiddle1.setRight(new Leaf("----// "));

		return root;
	}
	
	private static void	incorrectUsage(String msg) {
		System.err.println("This requires exactly one argument naming a strategy.");
		System.err.println(msg);
		System.exit(1);
	}
	
}

