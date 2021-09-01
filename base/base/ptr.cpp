#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <mutex>
#include <function>
using namespace std;

void unique_test()
{
    std::unique_ptr<int> up1(new int(11));
    // std::unique_ptr<int> up2 = up1; // 不能赋值只能move
    std::cout << *up1 << std::endl;
    std::unique_ptr<int> up3 = std::move(up1);
    std::cout << *up3 << std::endl;
    up3.reset();
    up1.reset();

    std::unique_ptr<int> up4(new int(12));
    up4.reset(new int(14)); // "动态绑定对象"
    std::cout << *up4 << std::endl;

    up4 = nullptr; //
    std::unique_ptr<int> up5(new int(15));
    int *p = up5.release(); // 只释放控制权，不释放内存
    std::cout << *p << std::endl;

    delete p; // 需要自己释放堆区空间
}

void shared_test()
{
    std::shared_ptr<int> sp1(new int(11));
    std::shared_ptr<int> sp2 = sp1;
    std::cout << "count:" << sp2.use_count() << std::endl;
    std::cout << *sp1 << " " << *sp2 << std::endl;
    sp1.reset(); // 显示让引用计数减1
    std::cout << "count:" << sp2.use_count() << std::endl;
    std::cout << *sp2 << std::endl;

    std::shared_ptr<int> sp3 = std::make_shared<int>(14);
    std::shared_ptr<std::string> sp4 = std::make_shared<std::string>(10, '9');
    std::shared_ptr<int> sp5 = std::make_shared<int>();
    auto sp6 = std::make_shared<std::vector<std::string>>();
    auto q(sp3);
}

void check(std::weak_ptr<int> &wp)
{
    std::shared_ptr<int> sp = wp.lock(); // 转换为shared_ptr<int>
    if (sp != nullptr)
    {
        std::cout << "still: " << *sp << std::endl;
    }
    else
    {
        std::cout << "still: "
                  << "pointer is invalid" << std::endl;
    }
}

void weak_test()
{
    /*
    weak_ptr是为配合shared_ptr而引入的一种智能指针来协助shared_ptr工作，它可以从一个shared_ptr或另一个weak_ptr对象构造，
    它的构造和析构不会引起引用计数的增加或减少。没有重载 *和 -> 但可以使用lock获得一个可用的shared_ptr对象.
    weak_ptr的使用更为复杂一点，它可以指向shared_ptr指针指向的对象内存，却并不拥有该内存，而使用weak_ptr成员lock，
    则可返回其指向内存的一个share_ptr对象，且在所指对象内存已经无效时，返回指针空值nullptr。
    注意：weak_ptr并不拥有资源的所有权，所以不能直接使用资源。 可以从一个weak_ptr构造一个shared_ptr以取得共享资源的所有权。
    */
    std::shared_ptr<int> sp1(new int(22));
    std::shared_ptr<int> sp2 = sp1;
    std::weak_ptr<int> wp = sp1; // 指向shared_ptr<int>所指对象

    std::cout << "count: " << wp.use_count() << std::endl; // count: 2
    std::cout << *sp1 << std::endl;                        // 22
    std::cout << *sp2 << std::endl;                        // 22
    check(wp);                                             // still: 22

    sp1.reset();
    std::cout << "count: " << wp.use_count() << std::endl; // count: 1
    std::cout << *sp2 << std::endl;                        // 22
    check(wp);                                             // still: 22

    sp2.reset();
    std::cout << "count: " << wp.use_count() << std::endl; // count: 0
    check(wp);                                             // still: pointer is invalid

    return;
}

/*
weak_ptr解决shared_ptr循环引用的问题
定义两个类，每个类中又包含一个指向对方类型的智能指针作为成员变量，然后创建对象，
设置完成后查看引用计数后退出，看一下测试结果：
*/

class CB;
class CA
{
public:
    CA() { std::cout << "CA() called! " << std::endl; }
    ~CA() { std::cout << "~CA() called! " << std::endl; }
    void set_ptr(std::shared_ptr<CB> &ptr)
    {
        m_ptr_b = ptr;
    }
    void b_use_count() { std::cout << "b use count : " << m_ptr_b.use_count() << std::endl; }
    void show() { std::cout << "this is class CA!" << std::endl; }

private:
    std::shared_ptr<CB> m_ptr_b;
    //std::weak_ptr<CB> m_ptr_b;
};

class CB
{
public:
    CB() { std::cout << "CB() called! " << std::endl; }
    ~CB() { std::cout << "~CB() called! " << std::endl; }
    void set_ptr(std::shared_ptr<CA> &ptr) { m_ptr_a = ptr; }
    void a_use_count() { std::cout << "a use count : " << m_ptr_a.use_count() << std::endl; }
    void show() { std::cout << "this is class CB!" << std::endl; }

private:
    std::shared_ptr<CA> m_ptr_a;
    // std::weak_ptr<CA> m_ptr_a;
};

void test_refer_to_each_other()
{
    std::shared_ptr<CA> ptr_a(new CA()); //  CA() called !
    std::shared_ptr<CB> ptr_b(new CB()); // CB() called !

    std::cout << "a use count : " << ptr_a.use_count() << std::endl; // a use count : 1
    std::cout << "b use count : " << ptr_b.use_count() << std::endl; // b use count : 1

    ptr_a->set_ptr(ptr_b);
    ptr_b->set_ptr(ptr_a);

    std::cout << "a use count : " << ptr_a.use_count() << std::endl; // a use count : 2
    std::cout << "b use count : " << ptr_b.use_count() << std::endl; // b use count : 2
}

void weak_test_1()
{
    /*
    weak_ptr中只有函数lock和expired两个函数比较重要，因为它本身不会增加引用计数，所以它指向的对象可能在它用的时候已经被释放了，
    所以在用之前需要使用expired函数来检测是否过期，然后使用lock函数来获取其对应的shared_ptr对象，然后进行后续操作
    */
    // 编译错误 // error C2665: “std::weak_ptr<CA>::weak_ptr”: 3 个重载中没有一个可以转换所有参数类型
    // weak_ptr<CA> ptr_1(new CA());

    // 编译错误
    // error C2440 : “初始化”: 无法从“std::weak_ptr<CA>”转换为“std::shared_ptr<CA>”
    // shared_ptr<CA> ptr_3 = wk_ptr;

    // 编译错误
    // 编译必须作用于相同的指针类型之间
    // wk_ptr_a.swap(wk_ptr_b);         // 调用交换函数

    // 编译错误
    // 编译必须作用于相同的指针类型之间
    // wk_ptr_b = wk_ptr_a;

    /*
    weak_ptr 一般被称为弱智能指针，其对资源的引用不会引起资源的引用计数的变化，通常作为观察者，
    用于判断资源是否存在，并根据不同情况做出相应的操作。比如使用 weak_ptr 对资源进行弱引用，
    当调用 weak_ptr 的 lock() 方法时，若返回 nullptr，则说明资源已经不存在，放弃对资源继续操作。
    否则，将返回一个 shared_ptr 对象，可以继续操作资源。另外，一旦最后一个指向对象的 shared_ptr 被销毁，
    对象就会被释放。即使有 weak_ptr 指向对象，对象也还是会被释放。
    */

    std::shared_ptr<CA> ptr_a(new CA()); // 输出：CA() called!
    std::shared_ptr<CB> ptr_b(new CB()); // 输出：CB() called!

    std::cout << "ptr_a use count : " << ptr_a.use_count() << std::endl; // 输出：ptr_a use count : 1
    std::cout << "ptr_b use count : " << ptr_b.use_count() << std::endl; // 输出：ptr_b use count : 1

    std::weak_ptr<CA> wk_ptr_a = ptr_a;
    std::weak_ptr<CB> wk_ptr_b = ptr_b;

    if (!wk_ptr_a.expired())
    {
        wk_ptr_a.lock()->show(); // 输出：this is class CA!
    }

    if (!wk_ptr_b.expired())
    {
        wk_ptr_b.lock()->show(); // 输出：this is class CB!
    }

    wk_ptr_b.reset(); // 将wk_ptr_b的指向清空
    if (wk_ptr_b.expired())
    {
        std::cout << "wk_ptr_b is invalid" << std::endl; // 输出：wk_ptr_b is invalid 说明改指针已经无效
    }

    wk_ptr_b = ptr_b;
    if (!wk_ptr_b.expired())
    {
        wk_ptr_b.lock()->show(); // 输出：this is class CB! 调用赋值操作后，wk_ptr_b恢复有效
    }

    // 最后输出的引用计数还是1，说明之前使用weak_ptr类型赋值，不会影响引用计数
    std::cout << "ptr_a use count : " << ptr_a.use_count() << std::endl; // 输出：ptr_a use count : 1
    std::cout << "ptr_b use count : " << ptr_b.use_count() << std::endl; // 输出：ptr_b use count : 1
}

template <class _Ty>
class auto_ptr
{
public:
    typedef _Ty element_type;

    explicit auto_ptr(_Ty *_Ptr = nullptr) noexcept
        : _Myptr(_Ptr) //初始化列表
    {                  //构造函数
    }

    auto_ptr(auto_ptr &_Right) noexcept
        : _Myptr(_Right.release())
    { //拷贝构造函数，会调用release()函数
    }

    _Ty *release() noexcept
    {
        /*使用拷贝构造时，最后一个auto_ptr持有资源，
   其余被置为nullptr*/
        _Ty *_Tmp = _Myptr;
        _Myptr = nullptr;
        return (_Tmp);
    }

private:
    _Ty *_Myptr; //指向资源
};

template <class T>
class scoped_ptr
{
private:
    T *px;
    scoped_ptr(scoped_ptr const &);            //拷贝构造函数
    scoped_ptr &operator=(scoped_ptr const &); //赋值构造函数

public:
    typedef T element_type;
    explicit scoped_ptr(T *p = nullptr) : px(p)
    {
    }
    ~scoped_ptr() //析构函数
};

template <class _Ty, class _Dx>
class unique_ptr : public _Unique_ptr_base<_Ty, _Dx>
{
public:
    typedef _Unique_ptr_base<_Ty, _Dx> _Mybase;
    typedef typename _Mybase::pointer pointer;
    typedef _Ty element_type;
    typedef _Dx deleter_type;

    unique_ptr(unique_ptr &&_Right) noexcept
        : _Mybase(_Right.release(),
                  _STD forward<_Dx>(_Right.get_deleter()))
    { // 右值引用的拷贝构造函数
    }

    unique_ptr &operator=(unique_ptr &&_Right) noexcept
    { //提供了右值引用的operator=赋值构造函数
        if (this != _STD addressof(_Right))
        {
            reset(_Right.release());
            this->get_deleter() = _STD forward<_Dx>(_Right.get_deleter());
        }
        return (*this);
    }
    /*
 删除了unique_ptr的拷贝构造和赋值函数，拒绝浅拷贝
 */
    unique_ptr(const unique_ptr &) = delete;
    unique_ptr &operator=(const unique_ptr &) = delete;
};

void auto_test()
{
    auto_ptr<int> ptr(new int(6)); //定义auto_ptr指针ptr
    auto_ptr<int> ptr1(ptr);       //拷贝构造ptr定义ptr1
    // *ptr = 8;                      //对空指针ptr赋值会产生不可预料的错误
    scoped_ptr<int> sp1(new int(6)); //初始化sp1指针
    //scoped_ptr<int> sp2(sp1);        //错误，无法拷贝构造
    scoped_ptr<int> sp3(new int(5)); //初始化sp2指针
    //sp1 = sp3;                       //错误，无法赋值

    std::unique_ptr<int> p1(new int(6)); //正确写法
    std::unique_ptr<int> p2(p1);         //这么写是错误的：
    // unique_ptr不支持拷贝
    std::unique_ptr<int> p3;
    // p3 = p2; //这么写是错误的：unique_ptr不支持赋值
}

/*
在多线程环境中，假设有一个对象池类 ObjectPool 和一个对象类 Object。
ObjectPool 类主要实现通过不同的 key 返回对应 Object 对象。
要求同一程序中由 Object 类实例出的不同对象只有一个，即当多处用到同一个对象，Object 对象应该被共享。
同时当对象不再需要时应该被析构，并删除对应的 key。
*/

class Object;
class ObjectPool
{
public:
    std::shared_ptr<Object> get(const string &key)
    {
        shared_ptr<Object> shObject;
        lock_guard lock(_mutex);
        weak_ptr<Object> &wkObject = object[key];
        shObject = wkObject.lock();
        //对象存在，提升成功并返回
        if (!shObject)
        {
            /*对象不存在，提升失败，shOject重新指向新创建的Object对象，并绑定回调函数，
            让对象Oject需要析构时调用OjectPool对象的成员函数*/
            shObject.reset(new Object(key), std::bind(&ObjectPool::deleteObject, this, _1));
            wkObject = shObject;
        }
        return shObject;
    }

private:
    void deleteObject(Object *obj)
    {
        /*回调函数，在对象需要析构时调用，从map中删除对象和对应的key*/
        if (obj)
        {
            lock_guard lock(_mutex);
            object.erase(obj->key());
        }
        delete obj;
    }

    mutable mutex _mutex;
    std::map<string, weak_ptr<Object>> object;
    /*map中不能使用shared_ptr，这会导致Oject对象永远不会被销毁*/
};