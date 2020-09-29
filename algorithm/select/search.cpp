#include "search.h"

int SequenceSearch(int a[], int value, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (value == a[i])
		{
			return i; // 找到位置为i
		}
	}
	return -1; // 没找到
}

int BinarySearch(int a[], int value, int n)
{
	int iLow = 0, iHigh = n, iMid;

	while (iLow <= iHigh)
	{
		iMid = iLow + (iHigh - iLow) / 2;
		if (value == a[iMid]) // 放在最后
		{
			return iMid;
		}
		else if (a[iMid] > value)
		{
			iHigh = iLow - 1;
		}
		else
		{
			iLow = iMid + 1;
		}
	}

	return -1;
}

int BinarySearchRecursion(int a[], int value, int low, int high)
{
	int mid = (high + low) / 2;
	if (a[mid] == value)
	{
		return mid;
	}

	if (a[mid] > value)
	{
		return BinarySearchRecursion(a, value, low, mid - 1);
	}

	if (a[mid] < value)
	{
		return BinarySearchRecursion(a, value, mid + 1, high);
	}
}

int InsertionSearch(int a[], int value, int low, int high)
{
	int mid = low + (value - a[low]) / (a[high] - a[low] * (high - low));
	if (a[mid] == value)
	{
		return mid;
	}
	if (a[mid] > value)
	{
		return InsertionSearch(a, value, low, mid - 1);
	}
	if (a[mid] < value)
	{
		return InsertionSearch(a, value, mid + 1, high);
	}
}

int FibonacciSearch(int *a, int n, int key)
{
	return 0;
}