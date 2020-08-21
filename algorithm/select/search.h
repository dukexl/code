#ifndef _SEARCH_H_
#define _SEARCH_H_


/*
1.顺序查找
*/

int SequenceSearch(int a[], int value, int n);

/*
2.二分查找
*/
int BinarySearch(int a[], int value, int n);


int InsertionSearch(int a[], int value, int low, int high);


int FibonacciSearch(int *a, int n, int key);

#endif