#include "recursion.h"
#include <time.h>
#include <stdio.h>
using namespace std;

int fib(int n)
{
	if (1 == n || 2==n)
	{
		return 1;
	}
	
	return fib(n - 1) + fib(n - 2);
}

int tailfib(int n, int acc1, int acc2)
{
	if (n < 2)
	{
		return acc1;
	}
	return tailfib(n - 1, acc2, acc1 + acc2);
}

int fibFor(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	
	int sum = 0, acc1 = 1, acc2 = 1;
	for (int i = 3; i <= n;i++)
	{
		sum = acc1 + acc2;
		acc1 = acc2;
		acc2 = sum;
	}

	return sum;
}

long long fac(int n)
{
	if (1 == n)
	{
		return 1;
	}
	else
	{
		return n * fac(n - 1);
	}
}

long long tailfac(int n, long long sum)
{
	if (1 == n)
	{
		return sum;
	}
	else
		return tailfac(n - 1, n * sum);
}

long long facFor(int n)
{
	long long  sum = 1;
	for (int i = 1; i <= n;i++)
	{
		sum *= i;
	}
	return sum;
}


void TestFib()
{
	clock_t start, finish;

	start = clock();
	printf("fib(40)=%d\n", fib(40));
	finish = clock();
	printf("耗时%lu\n", finish - start);

	start = clock();
	printf("fibFor(40)=%d\n", fibFor(40));
	finish = clock();
	printf("耗时%lu\n", finish - start);

	start = clock();
	printf("tailfib(40)=%d\n", tailfib(40, 1, 1));
	finish = clock();
	printf("耗时%lu\n", finish - start);

	start = clock();
	printf("fac(30)=%d\n", fac(30));
	finish = clock();
	printf("耗时%lu\n", finish - start);

	start = clock();
	printf("facFor(30)=%d\n", facFor(30));
	finish = clock();
	printf("耗时%lu\n", finish - start);

	start = clock();
	printf("tailfac(30)=%d\n", tailfac(30, 1));
	finish = clock();
	printf("耗时%lu\n", finish - start);
}

int max(int *values, int size)
{
	int mval = *values;
	int i;
	for (i = 1; i < size;i++)
	{
		if (values[i] > mval)
		{
			mval = values[i];
		}
	}
	return mval;
}

bool FinTNode(TNode* tr, int key)
{
	if (tr==NULL)
	{
		return false
	}

	if (tr->key == key)
	{
		return true
	}
	else
	{
		return FinTNode(tr->right, key);
	}
}

bool FinTNodeFor(TNode* tr, int key)
{
	TNode *curNode = tr;
	while (curNode != NULL)
	{
		if (curNode->key == key)
		{
			return true;
		}

		if (key < curNode->key)
		{
			curNode = curNode->left;
		}
		else
			curNode = curNode->right;
	}

	return false;
}

int main()
{
    TestFib();
	return 0;
}
