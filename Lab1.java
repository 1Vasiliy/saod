public class Lab1 {
    public static void main(String[] args)
    {
        int[] a = new int[10];
        fillRand(a);
        printMas(a);
    }

    public static void fillInc(int[] arr)
    {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
    }

    public static void fillDec(int[] arr)
    {
        for (int i = arr.length - 1; i >= 0; i--) {
            arr[arr.length - i - 1] = i;
        }
    }

    public static void fillRand(int[] arr)
    {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (int)(Math.random() * 100);
        }
    }

    public static int checkSum(int[] arr)
    {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }

    public static int runNumber(int[] arr)
    {
        int ser = 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) {
                ser++;
            }
        }
        return ser;
    }

    public static void printMas(int[] arr)
    {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print('\n');
    }
}
/*
1). Дан массив А из n целых чисел.
Разработать шесть сервисных процедур, которые будут использованы в следующих
лабораторных работах: a) процедуру FillInc, заполняющую массив А возрастающими
числами. b) процедуру FillDec, заполняющую массив А убывающими числами. c)
процедуру FillRand, заполняющую массив А случайными числами. d) функцию
CheckSum для подсчета контрольной суммы элементов массива А. e) функцию
RunNumber  для подсчета серий в массиве А. f) процедуру PrintMas для вывода на
экран элементов  массива А.

Массив А и кол-во n – параметры процедур !!!

2). Экспериментально определить:
  • кол-во серий в возрастающем массиве
  • кол-во серий в убывающем массиве

Определение.  Серией называется неубывающая последовательность максимальной
длины. Пример:  23145314  23  145  3  14   т.е. 4 серии

3).  Дополнительное задание (на 5+):
Экспериментально определить среднюю длину серии в случайном массиве.*/
