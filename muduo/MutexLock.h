#ifndef _MUTEX_LOCK_H_
#define _MUTEX_LOCK_H_
#include <pthread.h>

class MutexLock
{
private:
    pthread_mutex_t mutex_;
    pid_t holder_;

    public:
    MutexLock():holder_(0)
    {
        pthread_mutex_init(&mutex_,NULL);
    }

    ~MutexLock()
    {
        assert(holder_ == 0);
        pthread_mutex_destroy(&mutex_);
    }

    bool isLockedByThisThread()
    {
        return holder_ == CurrentThread::tid();
    }

    void assertLocked()
    {
        assert(isLockedByThisThread());
    }

    void lock()
    {
        pthread_mutex_lock(&mutex_);
        holder_ = CurrentThrad::tid();
    }

    void unlock()
    {
        holder_ =0;
        pthread_mutex_unlock(&mutex_);
    }

    pthread_mutex_t *getPthreadMutex()  // 仅供Condition调用，严禁用户代码调用
    {
        return &mutex_;
    }

};

#endif