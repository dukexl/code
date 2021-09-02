#pragma once
#include <iostream>
#include <cstring>

class Singleton
{
public:
	static Singleton &GetInstence()
	{
		return *pSingleton;
	}

private:
	static Singleton *pSingleton;
	Singleton() {}
	Singleton(const Singleton &other) = delete;
	Singleton &operator=(const Singleton &other) = delete;
};