import java.nio.charset.IllegalCharsetNameException;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
//        Scanner scan = new Scanner(System.in);
//
//        AVLtree tree = new AVLtree();
//
//        Btree t = new Btree();
//
//        Random rand = new Random(System.currentTimeMillis());
//
//        int[] intArray = new int[100];
//
//        for (int i = 0; i < intArray.length; i++) {
//            intArray[i] = rand.nextInt(1000);
//            t.insert(intArray[i]);
//        }
//        t.traversal();
//        tree.insert(intArray);
//
//        tree.traverseInOder();
//
//        for (int i = 0; i < 10; i++){
//            System.out.println();
//            tree.delete(scan.nextInt());
//            tree.traverseInOder();
//        }

        Integer[] arr = new Integer[4];
        arr[0] = 3;
        arr[1] = 7;
        arr[2] = 6;
        arr[3] = 5;
        Btree btree = new Btree();

//        Arrays.sort(arr, 0, 4);
        Integer[] arr1 = new Integer[100];

        btree.create(btree);
        for (Integer el: arr1) {
            el = (int)(Math.random()* 1000);
            btree.insert(btree, el);
            System.out.println(el);
        }

        btree.traversal(btree.root);
    }
}