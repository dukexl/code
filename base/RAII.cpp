#include <iostream>
#include <mutex>
#include <fstream>

using namespace std;

// 枚举类，防止enum里面的项冲突，或者用命名空间枚举
enum class shared_type
{
	circle,
	triangle,
	rectangle,
};

class shape
{
public:
	shape() { cout << "shape" << endl; }
	virtual void print() {
		cout << "I am shape!" << endl;
	}
	virtual ~shape(){}
};

class circle :public shape
{
public:
	circle() { cout << "circle" << endl; }
	void print() {
		cout << "I am circle!" << endl;
	}
};

class triangle :public shape
{
public:
	triangle() { cout << "triangle" << endl; }
	void print() {
		cout << "I am triangle!" << endl;
	}
};

class rectangle :public shape
{
public:
	rectangle() { cout << "rectangle" << endl; }
	void print() {
		cout << "I am rectangle!" << endl;
	}
};

shape* create_shape(shared_type type)
{
	switch (type)
	{
	case shared_type::circle:
		return new circle();
	case shared_type::triangle:
		return new triangle();
	case shared_type::rectangle:
		return new rectangle();
	default:
		break;
	}
	return nullptr;
}

class shape_wrapper
{
public:
	explicit shape_wrapper(shape* ptr = nullptr):ptr_(ptr){}
	~shape_wrapper()
	{
		delete ptr_;
	}

	shape* get()const {
		return ptr_;
	}

private:
	shape *ptr_;
};

void foo()
{
	shape_wrapper ptr(create_shape(shared_type::circle));
	ptr.get()->print();
}

class bar{};

void foo_heap()
{
	cout << "method 1" << endl;
	bar *ptr = new bar();
	delete ptr;
}

bar *make_bar() {
	bar *ptr = nullptr;
	try
	{
		ptr = new bar();
	}
	catch (...)
	{
		delete ptr;
		throw;
	}
	return ptr;
}

void foo_heap1()
{
	cout << "method 2" << endl;
	bar *ptr = make_bar();
	delete ptr;
}

class obj
{
public:
	obj() { puts("obj()"); }
	~obj() { puts("~obj"); }
};

void foo_stack(int n)
{
	obj _obj;
	if (n == 42)
	{
		throw "life ,the universe and everything";
	}
}

void test_stack()
{
	try
	{
		foo_stack(41);
		foo_stack(42);
	}
	catch (const char *s)
	{
		puts(s);
	}
}

int main()
{
	// 第一种方式
	shape *sp = create_shape(shared_type::circle);
	sp->print();
	delete sp;

	// 第二种
	foo();
	return 0;
}