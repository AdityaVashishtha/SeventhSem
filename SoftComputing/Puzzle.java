import java.util.*;




//class to store main function
public class Puzzle{
    public final static int BLOCK_SIZE = 3;

    public static void printf(String x) {
        System.out.println(x);
    }

    public static int calculateFValue(Block init,Block finl){
        int fCost = 0;
        for(int i=0;i<init.dimension;i++) {
            for(int j=0;j<init.dimension;j++){
                if((init.block[i][j] != finl.block[i][j]) && init.block[i][j] != 0 )
                    fCost = fCost + 1;
            }
        }
        return fCost;
    }

    public static Block bestNode(Queue<Block> open,Block finalState){
        int min=100000;
        Block ref = null;
        Iterator<Block> it = open.iterator();
        while(it.hasNext()) {
            Block temp = it.next();
            int x = calculateFValue(temp, finalState);            
            if(min > x ){
                ref = temp;
                min =x;
            }
        }
        return ref;
    }

    public static boolean checkElement(Queue<Block> q,Block b) {
        Iterator<Block> it = q.iterator();
        while(it.hasNext()) {
            if(it.next().equals(b))
                return true;
        }
        return false;
    }

    public static void solveAStar(Block initialState,Block finalState) {
        Queue<Block> open = new LinkedList<Block>();  
        Queue<Block> closed = new LinkedList<Block>();  
        initialState.cost = calculateFValue(initialState, finalState);
        open.add(initialState);        
        
        while(!open.isEmpty()) {
            Block curNode = bestNode(open,finalState);
            closed.add(curNode);
            open.remove(curNode);
            printf("----------");
            curNode.printBlock();
            printf("----------");
            if(curNode.cost == 0) {
                //TOOD Print path
                return;
            }     
            Block child;
            for (int i = 0; i < 4; i++)
            {
                switch(i) {
                    case 0: Block upChild = curNode;
                            if(upChild.blankUp(curNode)) {
                                // check closed set
                                if(! checkElement(closed, upChild))
                                    continue;
                                // check open set
                                if(! checkElement(open, upChild)) {
                                    upChild.cost = calculateFValue(upChild, finalState) + curNode.depth;
                                    upChild.depth = curNode.depth + 1;
                                    open.add(upChild);
                                }
                                // put in open set
                                int tempDepth = curNode.depth + 1;
                                if(tempDepth >= upChild.depth )
                                    continue;  
                                
                                upChild.depth = tempDepth;
                                upChild.parent = curNode;
                                upChild.cost = calculateFValue(upChild, finalState) + curNode.depth;
                            }
                            //up;
                    break;
                    case 1: Block downChild = curNode;
                            if(downChild.blankUp(curNode)) {
                                // check closed set
                                if(! checkElement(closed, downChild))
                                    continue;
                                // check open set
                                if(! checkElement(open, downChild)) {
                                    downChild.cost = calculateFValue(downChild, finalState) + curNode.depth;
                                    downChild.depth = curNode.depth + 1;
                                    open.add(downChild);
                                }
                                // put in open set
                                int tempDepth = curNode.depth + 1;
                                if(tempDepth >= downChild.depth )
                                    continue;  
                                
                                downChild.depth = tempDepth;
                                downChild.parent = curNode;
                                downChild.cost = calculateFValue(downChild, finalState) + curNode.depth;
                            }
                    break;
                    case 2: Block rChild = curNode;
                        if(rChild.blankUp(curNode)) {
                            // check closed set
                            if(! checkElement(closed, rChild))
                                continue;
                            // check open set
                            if(! checkElement(open, rChild)) {
                                rChild.cost = calculateFValue(rChild, finalState) + curNode.depth;
                                rChild.depth = curNode.depth + 1;
                                open.add(rChild);
                            }
                            // put in open set
                            int tempDepth = curNode.depth + 1;
                            if(tempDepth >= rChild.depth )
                                continue;  
                            
                            rChild.depth = tempDepth;
                            rChild.parent = curNode;
                            rChild.cost = calculateFValue(rChild, finalState) + curNode.depth;
                        }
                    break;
                    case 3: Block lChild = curNode;
                            if(lChild.blankUp(curNode)) {
                                // check closed set
                                if(! checkElement(closed, lChild))
                                    continue;
                                // check open set
                                if(! checkElement(open, lChild)) {
                                    lChild.cost = calculateFValue(lChild, finalState) + curNode.depth;
                                    lChild.depth = curNode.depth + 1;
                                    open.add(lChild);
                                }
                                // put in open set
                                int tempDepth = curNode.depth + 1;
                                if(tempDepth >= lChild.depth )
                                    continue;  
                                
                                lChild.depth = tempDepth;
                                lChild.parent = curNode;
                                lChild.cost = calculateFValue(lChild, finalState) + curNode.depth;
                            }
                    break;
                }
            }            
        }
    }

    //Main function to start Program
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int block[][] = new int[BLOCK_SIZE][BLOCK_SIZE];
        System.out.println("Input initial State");
        for(int i=0;i<BLOCK_SIZE;i++)
            for(int j=0;j<BLOCK_SIZE;j++) {
                block[i][j] = sc.nextInt();
            }
        
        Block initialState = new Block(block,BLOCK_SIZE);            
        initialState.setXY();

        System.out.println("Input Final State");
        for(int i=0;i<BLOCK_SIZE;i++)
            for(int j=0;j<BLOCK_SIZE;j++) {
                block[i][j] = sc.nextInt();
            }
        
        Block finalState = new Block(block,BLOCK_SIZE);            
        finalState.setXY();

        // FOR PRINTING FINAL AND INITIAL
        printf("");
        initialState.printBlock();        
        printf(initialState.blank_x+" "+initialState.blank_y);
        printf("");
        finalState.printBlock();        
        printf(finalState.blank_x+" "+finalState.blank_y);
        // FOR PRINTING FINAL AND INITIAL
        printf("");
        solveAStar(initialState,finalState);

    }


}


















class Block {
    int dimension;
    int cost;
    int blank_x, blank_y;
    int depth;
    int block[][] = new int[Puzzle.BLOCK_SIZE][Puzzle.BLOCK_SIZE];
    Block parent;

    Block(int block[][],int n) {
        this.depth = 1000000;
        this.dimension = n;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            this.block[i][j] = block[i][j];
        }
    }
    public void printBlock(){
        for(int x[]:block){
            for(int elem: x) {
                System.out.print(elem + " ");
            }            
            System.out.println();
        }
    }

    public void setXY(){
        blank_x = blank_y = -1;
        for(int i=0;i<Puzzle.BLOCK_SIZE && (blank_x == -1);i++) {
            for(int j=0;j<Puzzle.BLOCK_SIZE;j++)
            if(block[i][j]==0) {
                blank_x = i;
                blank_y = j;
                break;
            }
        }            
    }

    public boolean blankLeft(Block p){
        if((blank_x >= 0 && blank_x <= dimension-1) && ( blank_y > 0 &&  ( blank_y <= dimension-1)) ){
            int temp = block[blank_x][blank_y-1];
            block[blank_x][blank_y-1] = 0;
            block[blank_x][blank_y] = temp;
            blank_y = blank_y - 1;
            parent = p;
            return true;
        }
        return false;
    }

    public boolean blankRight(Block p){
        if((blank_x >= 0 && blank_x <= dimension-1) && ((blank_y >= 0) &&  ( blank_y < dimension-1))){
            int temp = block[blank_x][blank_y+1];
            block[blank_x][blank_y+1] = 0;
            block[blank_x][blank_y] = temp;
            blank_y = blank_y + 1;
            parent = p;
            return true;
        }
        return false;
    }

    public boolean blankDown(Block p){
        if((blank_x >= 0 && blank_x < dimension-1) && ( blank_y >= 0 &&  ( blank_y <= dimension-1)) ){
            int temp = block[blank_x+1][blank_y];
            block[blank_x+1][blank_y] = 0;
            block[blank_x][blank_y] = temp;
            blank_x = blank_x + 1;
            parent = p;
            return true;
        }
        return false;
    }

    public boolean blankUp(Block p){
        if((blank_x > 0 && blank_x <= dimension-1) && ( blank_y >= 0 &&  ( blank_y <= dimension-1)) ){
            int temp = block[blank_x-1][blank_y];
            block[blank_x-1][blank_y] = 0;
            block[blank_x][blank_y] = temp;
            blank_x = blank_x - 1;
            parent = p;
            return true;
        }
        return false;
    }
}