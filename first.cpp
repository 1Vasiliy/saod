
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tabTree {
  int data;
  struct tabTree *pleft;
  struct tabTree *preight;
};

typedef struct tabTree Tree;

/* Количество операций */
int op;

/* Прототипы функций */
void AddTree(Tree **root, int D);
Tree *BalansTree(int L, int R, int *mass);
int TreeFind(Tree *p);
int HeightTree(Tree *p);
int Find(Tree *root, int X);
/*********************/
int main(int argc, char const *argv[]) {
  Tree *root = NULL;
  int n, i, X;
  int *mass;

  system("chcp 1251 > nul");

  printf("\n Введите количество вершин в дереве (N):");
  scanf("%d", &n);

  system("cls");

  printf("\n Массив случайных чисел:\n\n");
  srand((unsigned)time(NULL));
  mass = (int *)malloc(sizeof(int) * n);
  if (mass == NULL) {
    printf("Memory error!");
    return 1;
  }

  for (i = 0; i < n; i++) {
    mass[i] = rand() % 99 + 1;
    printf("%3d", mass[i]);
    if (i != 0 && i % 10 == 0)
      printf("\n");
  }

  for (i = 0; i < n; i++) {
    AddTree(&root, mass[i]);
  }
  printf("\n\n ***************************************************");
  printf("\n ДЕРЕВО ПОСТРОЕНО!");
  printf("\n ***************************************************");
  printf("\n Введите вершину для поиска: ");
  scanf("%d", &X);

  printf("\n\n - Случайное дерево поиска (СДП)\n");
  printf("\t Высота дерева: %d", HeightTree(root));
  printf("\n\t %s деревом поиска", TreeFind(root) ? "Является" : "Не является");
  printf("\n\t Вершина %sнайдена", Find(root, X) ? "" : "не ");
  printf("\n\t Количество операций: %d", op);

  root = BalansTree(0, n, mass);
  printf("\n\n - Идеально сбалансированное дерево поиска (ИСДП)\n");
  printf("\t Высота дерева: %d", HeightTree(root));
  printf("\n\t %s деревом поиска", TreeFind(root) ? "Является" : "Не является");
  printf("\n\t Вершина %sнайдена", Find(root, X) ? "" : "не ");
  printf("\n\t Количество операций: %d", op);
  printf("\n\n");
  free(mass);
  /* code */
  return 0;
}

/* Случайное дерево поиска (СДП) */
void AddTree(Tree **root, int D) {
  Tree **p = root;

  while ((*p) != NULL) {
    if (D < (**p).data)
      p = &((**p).pleft);
    else
      p = &((**p).preight);
  }
  if ((*p) == NULL) {
    (*p) = (Tree *)malloc(sizeof(Tree));
    (**p).data = D;
    (**p).pleft = (**p).preight = NULL;
  }
}

/* Идеально сбалансированное дерево поиска (ИСДП) */
Tree *BalansTree(int L, int R, int *mass) {
  int m;
  Tree *p;

  if (L > R)
    return NULL;
  else {
    m = (L + R) / 2;
    p = (Tree *)malloc(sizeof(Tree));
    if (p == NULL) {
      printf("Memory error!");
      exit(1);
    }
    p->data = mass[m];
    p->pleft = BalansTree(L, m - 1, mass);
    p->preight = BalansTree(m + 1, R, mass);
    return p;
  }
}

/* Функция вычисления высоты дерева */
int HeightTree(Tree *p) {
  int pl = 0;
  int pr = 0;
  if (p == NULL)
    return 0;
  else {
    pl = HeightTree(p->pleft);
    pr = HeightTree(p->preight);
    return 1 + ((pl > pr) ? pl : pr);
  }
}

/* Является ли деревом поиска??? */
int TreeFind(Tree *p) {
  if ((p == NULL && (p->pleft != NULL &&
                     (p->data <= p->pleft->data || !TreeFind(p->pleft)))) ||
      (p->preight != NULL &&
       (p->data >= p->preight->data || !TreeFind(p->preight))))
    return 0;
  else
    return 1;
}
/* Поиск вершины */
int Find(Tree *root, int X) {
  Tree *p = root;

  op = 0;
  while (p != NULL) {
    op++;
    if (p->data == X)
      return 1;
    else
      p = (p->data > X) ? p->pleft : p->preight;
  }
  return 0;
}
/*
Write a class with the name SimpleCalculator. The class needs two fields
(instance variables) with names firstNumber and secondNumber both of type
double.

Write the following methods (instance methods):

*Method named getFirstNumber without any parameters, it needs to return the
value of firstNumber field. *Method named getSecondNumber without any
parameters, it needs to return the value of secondNumber field. *Method named
setFirstNumber with one parameter of type double, it needs to set the value of
the firstNumber field. *Method named setSecondNumber with one parameter of type
double, it needs to set the value of the secondNumberfield. *Method named
getAdditionResult without any parameters, it needs to return the result of
adding the field values of firstNumber and secondNumber. *Method named
getSubtractionResult without any parameters, it needs to return the result of
subtracting the field values of secondNumber from the firstNumber. *Method named
getMultiplicationResult without any parameters, it needs to return the result of
multiplying the field values of firstNumber and secondNumber. *Method named
getDivisionResult without any parameters it needs to return the result of
dividing the field values of firstNumber by the secondNumber. In case the value
of secondNumber is 0 then return 0.

TEST EXAMPLE

TEST CODE:

SimpleCalculator calculator = new SimpleCalculator();
calculator.setFirstNumber(5.0);
calculator.setSecondNumber(4);
System.out.println("add= " + calculator.getAdditionResult());
System.out.println("subtract= " + calculator.getSubtractionResult());
calculator.setFirstNumber(5.25);
calculator.setSecondNumber(0);
System.out.println("multiply= " + calculator.getMultiplicationResult());
System.out.println("divide= " + calculator.getDivisionResult());

OUTPUT

add= 9.0
subtract= 1.0
multiply= 0.0
divide= 0.0

TIPS:

*add= 9.0 is printed because 5.0 + 4 is 9.0
*subtract= 1.0 is printed because 5.0 - 4 is 1.0
*multiply= 0.0 is printed because 5.25 * 0 is 0.0
*divide= 0.0 is printed because secondNumber is set to 0


NOTE: All methods should be defined as public NOT public static.

NOTE: In total, you have to write 8 methods.

NOTE: Do not add the main method to the solution code.
*/
