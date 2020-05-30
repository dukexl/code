#ifndef _RECURSION_H_
#define _RECURSION_H_

int fib(int n);                          // 斐波那契数列递归算法
int tailfib(int n, int acc1, int acc2);  // 斐波那契数类尾递归算法
int fibFor(int n);

long long fac(int n);                    // N!递归算法
long long tailfac(int n, long long sum); // N!尾递归算法
long long facFor(int n);
void TestFib();

#endif