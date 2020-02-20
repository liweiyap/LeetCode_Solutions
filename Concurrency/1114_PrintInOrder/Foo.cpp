// Runtime: 136 ms, faster than 79.80% of C++ online submissions for Print in Order.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Print in Order.

#include <mutex>
#include <condition_variable>

class Foo
{
public:
    Foo(){}
    
    void first(function<void()> printFirst)
    {
        std::unique_lock<std::mutex> guard(m);
        cond.wait(guard, [&]{return iter == 0;});
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++iter; iter %= 3;
        cond.notify_all();
    }

    void second(function<void()> printSecond)
    {
        std::unique_lock<std::mutex> guard(m);
        cond.wait(guard, [&]{return iter == 1;});
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++iter; iter %= 3;
        cond.notify_all();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> guard(m);
        cond.wait(guard, [&]{return iter == 2;});
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        ++iter; iter %= 3;
        cond.notify_all();
    }
    
private:
    std::mutex m;
    std::condition_variable cond;
    int iter = 0;
};
