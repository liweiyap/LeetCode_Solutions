// Runtime: 296 ms, faster than 82.67% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Print FooBar Alternately.

#include <mutex>
#include <condition_variable>

class FooBar
{
private:
    int n;
    std::atomic<bool> isFoo;

public:
    FooBar(int n)
    {
        this->n = n;
        isFoo.store(true);
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {
            while (!isFoo.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            isFoo.store(false);
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; i++)
        {
            while (isFoo.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            isFoo.store(true);
        }
    }
};
