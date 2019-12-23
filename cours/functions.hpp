#pragma once

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <termios.h>
#include <unistd.h>

const int SIZE = 4000;
const char filename[] = "testBase.dat";

struct record {
  char author[12];
  char title[32];
  char publisher[16];
  short int year;
  short int numOfPage;
};

class shennonCoding {
private:
  char symbol;
  double probability;

  void shennonCode(shennonCoding *symbolProbability, int codePresent);
  void quickSort(shennonCoding *symbolProbability, int left, int right);

public:
  void codeBase();
};

class queue {
  record *arr[SIZE];
  int capacity = SIZE;
  int front = 0;
  int rear = -1;
  int count = 0;

public:
  // queue(int size = SIZE);
  int remove();
  void add(record *x);
  record *get();
  int size();
  bool isEmpty();
  bool isFull();
};

queue binarySearch(record *arr[], int left, int right, int key);
bool comparel(record *first, record *second);
void buildHeap(record data[], record *index[], int, int);
// void buildHeap(record *index[], int);
void heapSort(record data[], record *index[]);
// void heapSort(record data[], record *index[]);
void heapify(record *arr[], int n, int i);
void heapSort(record *arr[], int n);
void print(record *data[]);
void print(record data[]);
void viewTree();
void treeSearch(int value);
char *split(char *name);
char kbhit();
