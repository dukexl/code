#include "singleton.h"
#include <iostream>
using namespace std;

Singleton *Singleton::pSingleton = new Singleton();

int main(int argc, char *argv[])
{
	Singleton *singleton1 = &Singleton::GetInstence();
	Singleton *singleton2 = &Singleton::GetInstence();

	cout << singleton1 << endl;
	cout << singleton2 << endl;

	return 0;
}
