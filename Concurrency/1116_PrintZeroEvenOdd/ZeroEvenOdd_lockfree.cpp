// Runtime: 60 ms, faster than 35.63% of C++ online submissions for Print Zero Even Odd.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Print Zero Even Odd.

#include <atomic>
#include <thread>

class ZeroEvenOdd
{
private:
    int n;
    std::atomic<bool> isZero{true};
    std::atomic<bool> isEven{false};
    std::atomic<bool> isOdd{false};

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; ++i)
        {
            while (!isZero.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            printNumber(0);
            isZero.store(false);
            if (i % 2 == 0)
            {
                isEven.store(true);
            }
            else
            {
                isOdd.store(true);
            }
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            while (!isEven.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            printNumber(i);
            isEven.store(false);
            isZero.store(true);
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            while (!isOdd.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            printNumber(i);
            isOdd.store(false);
            isZero.store(true);
        }
    }
};
