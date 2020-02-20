// Runtime: 352 ms, faster than 49.59% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Print FooBar Alternately.

#include <mutex>
#include <condition_variable>

class FooBar
{
private:
    int n;
    std::mutex m;
    std::condition_variable cond;
    bool isFoo = true;

public:
    FooBar(int n)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo)
    {
        std::unique_lock<std::mutex> guard(m);
        
        for (int i = 0; i < n; i++)
        {
            cond.wait(guard, [&]{return isFoo;});
            
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            isFoo = false;
            cond.notify_all();
        }
    }

    void bar(function<void()> printBar)
    {
        std::unique_lock<std::mutex> guard(m);
        
        for (int i = 0; i < n; i++)
        {
            cond.wait(guard, [&]{return !isFoo;});
            
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            isFoo = true;
            cond.notify_all();
        }
    }
};
