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
			return true; // ���ݲ���ȷ
		}	
	}

	if (ilength == 1)
	{
		return false;
	}
	

	for (int i = 0; i < ilength;i++)
	{
		while (array[i] != i) // ���ģ�n��������[0:n-1],Ҫ�벻�ظ���ÿ��λ���ϱ���һһ��Ӧ��array[i]����i��λ���ϣ��Ͱ����ŵ�λ��i��ȥ
		{
			if (array[i] == array[array[i]]) // Ҫ���������ݲ�����ȣ������ȣ����ҳ����ˣ�������ﲻ���أ��ᵼ����ѭ��
			{
				iduplication = array[i]; //һ���ظ�����
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

// �ظ�����������������С������
void test1()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void test2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void test3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test5()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
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
