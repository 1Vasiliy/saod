import java.util.Random;

public class Main {
    public static void main(String[] args) {
        SearchTree recTree = new SearchTree();
        AVLtree tree = new AVLtree();

        Random rand = new Random(System.currentTimeMillis());

        int[] intArray = new int[100];

        for (int i = 0; i < intArray.length; i++) {
            intArray[i] = rand.nextInt(1000);
        }
        recTree.insert(intArray);
        tree.insert(intArray);

        System.out.println("Search tree:");
        recTree.traverseInOder();
        recTree.printInfo();

        System.out.println("AVL tree:");
        tree.traverseInOder();
        tree.printInfo();
    }
}