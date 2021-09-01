#include <iostream>
#include <string>
using namespace std;

void print()
{
	int i, j, k, f;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 30; j++)
			cout << " ";
		for (k = 1; k <= 8 - 2 * i; k++)
			cout << " ";
		for (f = 1; f <= 2 * i; f++)
			cout << '*';
		cout << endl;
	}
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 30; j++)
			cout << " ";
		for (f = 1; f <= 7 - 2 * i; f++)
			cout << '*';
		cout << endl;
	}
}

void isLeapYear()
{
	int year;
	bool isLeapYear;
	cout << "Enter the year: ";
	cin >> year;
	isLeapYear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	if (isLeapYear)
	{
		cout << year << " is a leap year" << endl;
	}
	else
	{
		cout << year << " is not a leap year" << endl;
	}
}

void annotation()
{
	//另一种注释方法
#if 0
	cout << "关闭注释" << endl;
#endif

	//打开注释
	//条件编译指令
#if 1
	cout << "打开注释" << endl;
#endif
}

union myunion
{
	struct
	{
		int x;
		int y;
		int z;
	} u;
	int k;
} a;

void myun()
{
	a.u.x = 4;
	a.u.y = 5;
	a.u.z = 6;
	a.k = 0; //覆盖掉第一个int空间值
	printf("%d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k);
}

void c11()
{
	string str("some string");
	for (auto &c : str)
	{
		c = static_cast<char>(toupper(c));
	}
	cout << str << endl;
}

int main(int argc, char const *argv[])
{
	isLeapYear();
	annotation();
	myun();
	c11();
	return 0;
}