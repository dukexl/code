#include <iostream>
using namespace std;

bool duplicate(int array[], int ilength, int &iduplication)
{
	// check data correct
	if (array == nullptr || ilength <=0)
	{
		return true;
	}	

	for (int i = 0; i < ilength;i++)
	{
		if (array[i]<0 || array[i] >=ilength)
		{
			return true; // 数据不正确
		}	
	}

	if (ilength == 1)
	{
		return false;
	}
	

	for (int i = 0; i < ilength;i++)
	{
		while (array[i] != i) // 核心：n个数都在[0:n-1],要想不重复，每个位置上必须一一对应，array[i]不在i的位置上，就把它放到位置i上去
		{
			if (array[i] == array[array[i]]) // 要交互的数据不能相等，如果相等，就找出来了，如果这里不返回，会导致死循环
			{
				iduplication = array[i]; //一个重复的书
				return true;
			}
			int tmp = array[i];
			array[i] = array[tmp];
			array[tmp] = tmp;			
		}
	}
	return false;
}


bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return true;
	}

	return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
	printf("%s begins: ", testName);

	int duplication;
	bool validInput = duplicate(numbers, lengthNumbers, duplication);

	if (validArgument == validInput)
	{
		if (validArgument)
		{
			if (contains(expected, expectedExpected, duplication))
				printf("Passed.\n");
			else
				printf("FAILED.\n");
		}
		else
			printf("Passed.\n");
	}
	else
		printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the test function
	test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int  main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
//	system("pause");
	return 0;
}
