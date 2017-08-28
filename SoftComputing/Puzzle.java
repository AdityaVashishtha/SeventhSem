import java.util.Scanner;




//class to store main function
public class Puzzle{
    public final static int BLOCK_SIZE = 3;

    //Main function to start Program
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Block initialState = new Block();
        System.out.println("Input initial State");
        for(int i=0;i<BLOCK_SIZE;i++)
            for(int j=0;j<BLOCK_SIZE;j++) {
                initialState.block[i][j] = sc.nextInt();
            }
        initialState.printBlock();
    }





}


















class Block {
    int cost;
    int blank_x, blank_y;
    int block[][] = new int[Puzzle.BLOCK_SIZE][Puzzle.BLOCK_SIZE];
    Block parent;
    public void printBlock(){
        for(int x[]:block){
            for(int elem: x) {
                System.out.print(elem + " ");
            }            
            System.out.println();
        }
    }
}