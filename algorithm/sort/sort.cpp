#include "sort.h"
#include <iostream>
using namespace std;

void Print(int a[], int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;
}

void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1]) //升序
		{
			int j = i - 1;
			int x = a[i];
			a[i] = a[i - 1];
			while (x < a[j] && j >= 0)
			{
				a[j + 1] = a[j];
				j--;
			}
		}
	}
}

void ShellInsertSort(int a[], int n, int dk)
{
	for (int i = dk; i < n; ++i)
	{
		if (a[i] < a[i - dk])
		{
			int j = i - dk;
			int x = a[i];
			a[i] = a[i - dk];

			while (x < a[j] && j >= 0)
			{
				a[j + dk] = a[j];
				j -= dk;
			}
			a[j + dk] = x;
		}
	}
}

void ShellSort(int a[], int n)
{
	int dk = n / 2; // 希尔序列（n/2,n/4,....1)
	while (dk >= 1)
	{
		ShellInsertSort(a, n, dk);
		dk = dk / 2;
	}
}

int SelectMinKey(int a[], int n, int i)
{
	int k = i;
	for (int j = i + 1; j < n; ++j)
	{
		if (a[k] > a[j])
		{
			k = j;
		}
	}
	return k;
}

void selectSort(int a[], int n)
{
	int key, tmp;
	for (int i = 0; i < n; ++i)
	{
		key = SelectMinKey(a, n, i);
		if (key != i)
		{
			tmp = a[i];
			a[i] = a[key];
			a[key] = tmp;
		}
	}
}

void SelectSortTwo(int a[], int n)
{
	int i, j, min, max, tmp;
	for (i = 1; i <= n / 2; i++)
	{
		min = max = i;
		for (j = i + 1; j <= n - i; j++)
		{
			if (a[j] > a[max])
			{
				max = j;
			}

			if (a[j] < a[min])
			{
				min = j;
			}
		}
		tmp = a[i - 1];
		a[i - 1] = a[min];
		a[min] = tmp;

		tmp = a[n - i];
		a[n - i] = a[max];
		a[max] = tmp;
	}
}

void HeapAdjust(int a[], int s, int length)
{
	int tmp = a[s];
	int child = 2 * s + 1;
	while (child < length)
	{
		if (child + 1 < length && a[child] < a[child + 1])
		{
			++child;
		}

		if (a[s] < a[child])
		{
			a[s] = a[child];
			s = child;
			child = 2 * s + 1;
		}
		else
		{
			break;
		}
		a[s] = tmp;
	}
}

void BuildingHeap(int a[], int length)
{
	for (int i = (length - 1) / 2; i >= 0; --i)
	{
		HeapAdjust(a, i, length);
	}
}

void HeapSort(int a[], int length)
{
	//初始堆
	BuildingHeap(a, length);

	// 从最后一个元素开始对序列进行调整
	for (int i = length - 1; i > 0; --i)
	{
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		HeapAdjust(a, 0, i);
	}
}

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void bubbleSort1(int a[], int n)
{
	int i = n - 1;
	while (i > 0)
	{
		int pos = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				pos = j;
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			i = pos;
		}
	}
}

void bubbleSort2(int a[], int n)
{
	int low = 0;
	int high = n - 1;
	int tmp, j;
	while (low < high)
	{
		for (j = low; j < high; ++j)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		--high;
		for (j = high; j > low; --j)
		{
			if (a[j] < a[j - 1])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
		++low;
	}
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int a[], int low, int high)
{
	int privotKey = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= privotKey)
		{
			--high;
		}
		swap(a[low], a[high]);

		while (low < high && a[low] <= privotKey)
		{
			++low;
		}
		swap(a[low], a[high]);
	}
	return low;
}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int privotLoc = partition(a, low, high);
		quickSort(a, low, privotLoc - 1);
		quickSort(a, privotLoc + 1, high);
	}
}

void quickSortImprove(int a[], int low, int high, int k)
{
	if (high - low > k)
	{
		int pivot = partition(a, low, high);
		quickSortImprove(a, low, pivot - 1, k);
		quickSortImprove(a, pivot + 1, high, k);
	}
}

void Merge(int *a, int *b, int i, int m, int n)
{
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
	{
		if (a[j] < a[i])
		{
			b[k] = a[j++];
		}
		else
		{
			b[k] = a[i++];
		}
	}
	while (i <= m)
	{
		b[k++] = a[i++];
	}
	while (j <= n)
	{
		b[k++] = a[j++];
	}
}

void MergeSort(int *a, int *b, int length)
{
	int len = 1;
	int *q = a;
	int *tmp;

	while (len < length)
	{
		int s = len;
		len = 2 * s;
		int i = 0;
		while (i + len < length)
		{
			Merge(q, b, i, i + s - 1, i + len - 1);
			i = i + len;
		}

		if (i + s < length)
		{
			Merge(q, b, i, i + s - 1, length - 1);
		}
		tmp = q;
		q = b;
		b = tmp;
	}
}

void Msort(int *a, int *b, int s, int t)
{
	int *tmp = b;
	if (s == t)
	{
		a[s] = b[s];
	}
	else
	{
		int m = (s + t) / 2;
		Msort(a, tmp, s, m);
		Msort(a, tmp, m + 1, t);
		Merge(tmp, b, s, m + 1, t);
	}
}

void MergeSortRecusive(int *a, int *b, int n)
{
	Msort(a, b, 0, n - 1);
}

void RadixSort(int a[], int m, int n)
{
}