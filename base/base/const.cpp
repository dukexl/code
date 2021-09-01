/*
1.const含义：常类型，修饰的变量和对象不能被修改
2.作用 1）定义常量 2）类型检查（只有修饰的是int和enum变量，该变量才可以被认为是常量） 3）防止修改，起到保护作用，增强程序健壮型 4）节省内存
3.const对象默认为文件局部变量：非const变量默认为extern，要使const变量能够在其他文件中访问，必须在文件中显式地指定为extern
4.因为常量在定义后就不能被修改，所以定义时必须初始化。
5.指针与const; const char *a; char const *a ; char * const a(常指针); const char* const a;
  //如果const位于*的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；如果const位于*的右侧，const就是修饰指针本身，即指针本身是常量
6.const在函数中 const int f(); const *int f(); *int const f() ;入参
7.const在类中
*/
#include <stdio.h>
int main()
{
  const int i = 10;
  int *p = (int *)(&i);
  *p = 20;
  printf("i=%d *p=%d \n", i, *p);
  return 0;
}

/*
我们知道C语言中const表示只读的变量，既然把const看成是变量，那么其在内存中就会有存储他的空间，
并且可以通过指针间接的改变该内存空间的值，当通过指针p改变该内存中的值后，再获取i的值的时候，
会访问该空间，得到的是被改变后的值。

而C++把const看做常量，编译器会使用常数直接替换掉对i的引用，例如cout<<i; 会理解成cout<<10; 
并不会去访问i的内存地址去取数据，这里有点像是C语言里的宏#define i 10。因此C++里i会输出10，而*p会输出20. 
*/