import java.util.*;

public class Perceptron {

    static double w1,w2,b;
    static double learningRate = 1;


    public static void main(String args[]){
        int [] inputX1 = {0,1,0,1,0};
        int [] inputX2 = {0,0,1,1,0};

        // Output as per gate
        int []outputAnd = {0,0,0,1,0};
        int []outputOr = {0,1,1,1,0};
        int []outputNand = {1,1,1,0,1};
        int []outputNor = {1,0,0,0,1};

        w1 = new Random().nextDouble() + -1;
        w2 = new Random().nextDouble() + -1;
        b = new Random().nextDouble() + -1;
        
        System.out.println("Weight Before "+w1+",  "+w2+",  "+b);

        int maxIter = 20;
        for(int i=0;i<maxIter;i++) {
            for(int j=0;j<inputX1.length;j++) {
                int x1 = inputX1[j];
                int x2 = inputX2[j];
                int op = outputNor[j];
                double weightedSum = w1*x1 + w2*x2;
                double totalSum = weightedSum + b ;
                int y = (totalSum > 0 ) ? 1 : 0;
                int t = op - y;
                double alphaTX1 = learningRate*t*x1; 
                double alphaTX2 = learningRate*t*x2;

                w1 = w1 + alphaTX1;
                w2 = w2 + alphaTX2;

                b = b + (learningRate*t);

            }
        }
        System.out.println("Weight after "+w1+",  "+w2+",  "+b);
        for(int j=0;j<inputX1.length;j++) {
            int x1 = inputX1[j];
            int x2 = inputX2[j];
            int op = outputNor[j];
            double weightedSum = w1*x1 + w2*x2;
            double totalSum = weightedSum + b ;
            int y = (totalSum > 0 ) ? 1 : 0;
            System.out.println("New Output :: "+y+" Old("+op+")");
        }
    }
}