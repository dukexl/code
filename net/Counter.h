#ifndef _COUNTER_H_
#define _COUNTER_H_
#include "MutexLock.h"

class Counter:boost::noncopyable
{
private:
    int64_t value_;
    mutable MutexLock mutex_;  // const成员函数如value()也能直接使用non-const的mutex_, 
    // 如果是static，只会影响性能，不会影响正确性

public:
    Counter():value_(0){}
    int64_t value() const;
    int64_t getAndIncrease();
};

#endif