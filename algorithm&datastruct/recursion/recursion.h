#ifndef _RECURSION_H_
#define _RECURSION_H_

int fib(int n);                          // 쳲��������еݹ��㷨
int tailfib(int n, int acc1, int acc2);  // 쳲���������β�ݹ��㷨
int fibFor(int n);

long long fac(int n);                    // N!�ݹ��㷨
long long tailfac(int n, long long sum); // N!β�ݹ��㷨
long long facFor(int n);
void TestFib();

#endif