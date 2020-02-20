// Runtime: 36 ms, faster than 83.99% of C++ online submissions for Fizz Buzz Multithreaded.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Fizz Buzz Multithreaded.

#include <mutex>
#include <condition_variable>

class FizzBuzz
{
private:
    int n;
    std::mutex m;
    std::condition_variable cond;
    int iter = 1;
    
    bool isFizz = false;
    bool isBuzz = false;
    bool isFizzBuzz = false;
    bool isNumber = true;

public:
    FizzBuzz(int n)
    {
        this->n = n;
    }
    
    void check(int i)
    {
        if (i > n)
        {
            isFizz = true;
            isBuzz = true;
            isFizzBuzz = true;
            isNumber = true;
        }
        else if (i % 3 == 0 && i % 5 == 0)
        {
            isFizz = false;
            isBuzz = false;
            isFizzBuzz = true;
            isNumber = false;
        }
        else if (i % 3 == 0)
        {
            isFizz = true;
            isBuzz = false;
            isFizzBuzz = false;
            isNumber = false;
        }
        else if (i % 5 == 0)
        {
            isFizz = false;
            isBuzz = true;
            isFizzBuzz = false;
            isNumber = false;
        }
        else
        {
            isFizz = false;
            isBuzz = false;
            isFizzBuzz = false;
            isNumber = true;
        }
    }
    
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        std::unique_lock<std::mutex> guard(m);
        while (iter <= n)
        {
            cond.wait(guard, [&]{return isFizz;});
            if (iter > n)
            {
                return;
            }
            printFizz();
            check(++iter);
            cond.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        std::unique_lock<std::mutex> guard(m);
        while (iter <= n)
        {
            cond.wait(guard, [&]{return isBuzz;});
            if (iter > n)
            {
                return;
            }
            printBuzz();
            check(++iter);
            cond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        std::unique_lock<std::mutex> guard(m);
        while (iter <= n)
        {
            cond.wait(guard, [&]{return isFizzBuzz;});
            if (iter > n)
            {
                return;
            }
            printFizzBuzz();
            check(++iter);
            cond.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        std::unique_lock<std::mutex> guard(m);
        while (iter <= n)
        {
            cond.wait(guard, [&]{return isNumber;});
            if (iter > n)
            {
                return;
            }
            printNumber(iter);
            check(++iter);
            cond.notify_all();
        }
    }
};
