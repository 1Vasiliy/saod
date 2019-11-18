#pragma once

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <termios.h>
#include <unistd.h>

const int SIZE = 4000;

struct record {
  char author[12];
  char title[32];
  char publisher[16];
  short int year;
  short int numOfPage;
};

std::queue<record *> binarySearch(record *arr[], int left, int right, int key);
bool comparel(record *first, record *second);
void buildHeap(record data[], record *index[], int, int);
// void buildHeap(record *index[], int);
void heapSort(record data[], record *index[]);
// void heapSORT(record data[], record *index[]);
void heapify(record *arr[], int n, int i);
void heapSORT(record *arr[], int n);
void print(record *data[]);
void print(record data[]);
char *split(char *name);
char kbhit();
