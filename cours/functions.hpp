#pragma once

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
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

void buildHeap(record vector[], record *index[], int, int);
void heapSort(record vector[], record *index[]);
void print(record *data[]);
void print(record data[]);
char *split(char *name);
void kbhit();
