#include "MathFunctions.h"

int algSqrt(int a, int b)
{
	int sum = 1;
	for (int i = 0; i < b;i++)
	{
		sum *= a;
	}
	return sum;
}