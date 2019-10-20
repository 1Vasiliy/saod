
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        PerfSearchTree perfTree = new PerfSearchTree();
        SearchTree tree = new SearchTree();
        SearchTree recTree = new SearchTree();
        Scanner scan = new Scanner(System.in);

        Random rand = new Random(System.currentTimeMillis());

        int[] intArray = new int[100];

        for (int i = 0; i < intArray.length; i++){
            intArray[i] = rand.nextInt(1000);
//            System.out.print(intArray[i] + " ,");
            tree.insert(intArray[i]);
        }
//        System.out.println("Search tree:");
//        tree.traverseInOder();
//
//        tree.printInfo();
//
//        System.out.println("Recursive insert method");
//        recTree.insert(intArray);
//        recTree.traverseInOder();
//        recTree.printInfo();
//
//
//        System.out.println("\nPerfect balanced search tree:");
//        Arrays.sort(intArray);
//        perfTree.insert(intArray);
//        perfTree.traverseInOder();
//        perfTree.printInfo();
//
//        int value = 0;
//
//        while (value != -1) {
//            value = scan.nextInt();
//            System.out.println(tree.get(value));
//
//            System.out.println();
//        }
//        showLab3(tree);
//    }
//
//    public static void showLab3(SearchTree tree){
//        Scanner scan = new Scanner(System.in);
//        for (int i = 0; i < 10; i++){
//        tree.traverseInOder();
//            System.out.println();
//        tree.delete(scan.nextInt());


//       }

        SearchTree tree0 = new SearchTree();


    }
}