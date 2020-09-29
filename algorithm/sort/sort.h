#ifndef _SORT_H_
#define _SORT_H_

void InsertSort(int a[], int n);

void ShellInsertSort(int a[], int n, int dk);

void selectSort(int a[], int n);

void HeapAdjust(int H[], int s, int length);

void bubbleSort(int a[], int n);

void quickSort(int a[], int low, int high);

void Merge(int *r, int *rf, int i, int m, int n);

void RadixSort(int a[], int x, int y);

void Print(int a[], int n, int i);

#endif