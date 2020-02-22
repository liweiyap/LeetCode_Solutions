// Runtime: 152 ms, faster than 63.67% of C++ online submissions for Print in Order.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Print in Order.

#include <atomic>
#include <thread>
#include <chrono>

class Foo
{
public:
    Foo()
    {
        iter.store(0);
    }

    void first(function<void()> printFirst)
    {
        updateIter(0, 1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        iter.store(2);
    }

    void second(function<void()> printSecond)
    {
        updateIter(2, 3);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        iter.store(4);
    }

    void third(function<void()> printThird)
    {
        updateIter(4, 5);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        iter.store(0);
    }
    
    void updateIter(int src, int dst)
    {
        int expected = src;
        /*
         * atomically compare iter and expected;
         * if equal, replace iter with dst;
         * else, replace expected with iter
         */
        while (!iter.compare_exchange_weak(expected, dst))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            expected = src;
        }
    }
    
private:
    std::atomic<int> iter;
};
