public class Lab2 {
    private static int[] firstArr = new int[20];
    private static int[] secondArr = new int[40];
    private static int c = 0;
    private static int m = 0;

    public static void main(String[] args)
    {
        Lab1.fillInc(firstArr);
        Lab1.fillInc(secondArr);
        System.out.print("\t\t~~~INCREASING~~~\n");
        printInfo(firstArr);

        Lab1.fillDec(firstArr);
        Lab1.fillDec(secondArr);
        System.out.print("\t\t~~~DECREASING~~~\n");
        printInfo(firstArr);

        Lab1.fillRand(firstArr);
        Lab1.fillRand(secondArr);
        System.out.print("\t\t~~~RANDOM~~~\n");
        printInfo(firstArr);
    }

    public static void selectSort(int[] arr)
    {
        m = 0;
        c = 0;
        int k = 0;
        int temp = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            k = i;
            for (int j = i + 1; j < arr.length; j++) {
                c++;
                if (arr[j] < arr[k]) {
                    k = j;
                }
            }
            if (k != i) {
                temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
                m++;
            }
        }
    }
    public static void printInfo(int[] arr)
    {
        if (arr.length == 20) { // bad condition
            System.out.print("First array : ");
        } else
            System.out.print("\nSecond array : ");

        Lab1.printMas(arr);
        System.out.println(
                "Before sorting:\nControl sum: " + Lab1.checkSum(arr) + " \n"
                + "Num of series: " + Lab1.runNumber(arr) + " \n");

        selectSort(arr);
        System.out.print("Sorted: ");
        Lab1.printMas(arr);

        System.out.println(
                "After sorting:\nControl sum: " + Lab1.checkSum(arr) + " \n"
                + "Num of series: " + Lab1.runNumber(arr) + " \n");

        System.out.println("Compares and moves(f): " + c + " " + 3 * m);

        m = 3 * (arr.length - 1);
        c = (int)((Math.pow(arr.length, 2) - arr.length) / 2);

        System.out.println("Compares and moves(t): " + c + " " + m + " \n");

        if (arr.length == 20)
            printInfo(secondArr);
    }
}
