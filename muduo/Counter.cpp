#include "Counter.h"
#include "MutexLockGuard.h"

int64_t Counter::value() const{
    MutexLockGuard lock(mutex_);
    return value_;
}
//实际项目中，这个class用原子操作更合理，这里用锁仅仅为了举例

int64_t Counter::getAndIncrease()
{
    MutexLockGuard lock(mutex_);
    int64_t ret = value_++;
    return ret;
}