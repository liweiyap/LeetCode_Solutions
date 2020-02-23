// Runtime: 32 ms, faster than 87.94% of C++ online submissions for Fizz Buzz Multithreaded.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Fizz Buzz Multithreaded.

#include <atomic>
#include <thread>

class FizzBuzz
{
private:
    int n;
    std::atomic<int> iter{1};
    std::atomic<bool> isFizz{false};
    std::atomic<bool> isBuzz{false};
    std::atomic<bool> isFizzBuzz{false};
    std::atomic<bool> isNumber{true};

public:
    FizzBuzz(int n)
    {
        this->n = n;
    }
    
    void check()
    {
        if (iter.load() > n)
        {
            isFizz.store(true);
            isBuzz.store(true);
            isFizzBuzz.store(true);
            isNumber.store(true);
        }
        else if (iter % 3 == 0 && iter % 5 == 0)
        {
            isFizz.store(false);
            isBuzz.store(false);
            isFizzBuzz.store(true);
            isNumber.store(false);
        }
        else if (iter % 3 == 0)
        {
            isFizz.store(true);
            isBuzz.store(false);
            isFizzBuzz.store(false);
            isNumber.store(false);
        }
        else if (iter % 5 == 0)
        {
            isFizz.store(false);
            isBuzz.store(true);
            isFizzBuzz.store(false);
            isNumber.store(false);
        }
        else
        {
            isFizz.store(false);
            isBuzz.store(false);
            isFizzBuzz.store(false);
            isNumber.store(true);
        }
    }
    
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (iter.load() <= n)
        {
            while (!isFizz.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            if (iter.load() > n)
            {
                return;
            }
            printFizz();
            iter.fetch_add(1);
            check();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (iter.load() <= n)
        {
            while (!isBuzz.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            if (iter.load() > n)
            {
                return;
            }
            printBuzz();
            iter.fetch_add(1);
            check();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (iter.load() <= n)
        {
            while (!isFizzBuzz.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            if (iter.load() > n)
            {
                return;
            }
            printFizzBuzz();
            iter.fetch_add(1);
            check();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (iter.load() <= n)
        {
            while (!isNumber.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            if (iter.load() > n)
            {
                return;
            }
            printNumber(iter.load());
            iter.fetch_add(1);
            check();
        }
    }
};
