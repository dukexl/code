#ifndef _RECURSION_H_
#define _RECURSION_H_
struct TNode
{
	int key;
	TNode *next;
}
int fib(int n);                        
int tailfib(int n, int acc1, int acc2);  
int fibFor(int n);

long long fac(int n);                  
long long tailfac(int n, long long sum); 
long long facFor(int n);
void TestFib();

#endif