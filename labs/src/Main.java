import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        AVLtree tree = new AVLtree();

        Random rand = new Random(System.currentTimeMillis());

        int[] intArray = new int[100];

        for (int i = 0; i < intArray.length; i++) {
            intArray[i] = rand.nextInt(1000);
        }
        tree.insert(intArray);

        tree.traverseInOder();

        for (int i = 0; i < 10; i++){
            System.out.println();
            tree.delete(scan.nextInt());
            tree.traverseInOder();
        }
    }
}