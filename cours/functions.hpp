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
void buildHeapAuthor(record data[], record *index[], int, int);
void buildHeapYear(record data[], record *index[], int, int);
void heapSort(record data[], record *index[], int flag);
void print(record *data[]);
void print(record data[]);
char *split(char *name);
char kbhit();
