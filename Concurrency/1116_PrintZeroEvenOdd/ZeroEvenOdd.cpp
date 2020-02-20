// Runtime: 64 ms, faster than 27.87% of C++ online submissions for Print Zero Even Odd.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Print Zero Even Odd.

class ZeroEvenOdd
{
private:
    int n;
    std::mutex m;
    std::condition_variable cond;
    bool printZero = true;
    bool printEven = false;
    bool printOdd = false;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        std::unique_lock<std::mutex> guard(m);
        for (int i = 1; i <= n; ++i)
        {
            cond.wait(guard, [&]{return printZero;});
            printNumber(0);
            printZero = false;
            if (i % 2 == 0)
            {
                printEven = true;
            }
            else
            {
                printOdd = true;
            }
            cond.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        std::unique_lock<std::mutex> guard(m);
        for (int i = 2; i <= n; i += 2)
        {
            cond.wait(guard, [&]{return printEven;});
            printNumber(i);
            printEven = false;
            printZero = true;
            cond.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        std::unique_lock<std::mutex> guard(m);
        for (int i = 1; i <= n; i += 2)
        {
            cond.wait(guard, [&]{return printOdd;});
            printNumber(i);
            printOdd = false;
            printZero = true;
            cond.notify_all();
        }
    }
};
