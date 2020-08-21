#ifndef _MUTEX_LOCK_GUARD_H_
#define _MUTEX_LOCK_GUARD_H_

class MutexLockGuard:boost::noncopyable
{
public:
    explicit MutexLockGuard(MutexLock &mutex):mutex_(mutex)
    {
        mutex_.lock();
    }

    ~MutexLockGuard()
    {
        mutex_unlock();
    }


private:
    MutexLock& mutex_;
}

#define MutexLockGuard(x) static_assert(false,"missing mutex guard var nmae") 
// 防止程序出现错误
/*
void doit()
{
    MutexLockGuard(mutex_); // 遗漏变量名，产生一个临时对象又马上销毁了，结果没有锁住临界区
    // 正确的 MutexLockGuard lock(mutex_);
}
*/


#endif