#pragma once

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <termios.h>
// #include "queue.cpp"
#include <unistd.h>

const int SIZE = 4000;

struct record {
  char author[12];
  char title[32];
  char publisher[16];
  short int year;
  short int numOfPage;
};


class queue
{
	record *arr[SIZE];
	int capacity = SIZE;
	int front = 0;
	int rear = -1;
	int count = 0;

public:
	// queue(int size = SIZE);

	void remove();
	void add(record* x);
	record* peek();
	int size();
	bool isEmpty();
	bool isFull();
};


queue binarySearch(record *arr[], int left, int right, int key);
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
