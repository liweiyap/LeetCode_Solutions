// Runtime: 188 ms, faster than 77.67% of C++ online submissions for Building H2O.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Building H2O.

#include <atomic>
#include <thread>

class H2O
{
public:
    H2O(){}
    
    void conditionalReset()
    {
        if (nHydrogen.load() == 2 && nOxygen.load() == 1)
        {
            nHydrogen.store(0);
            nOxygen.store(0);
        }
    }
    
    void hydrogen(function<void()> releaseHydrogen)
    {
        int expected = 2;
        /*
         * if nHydrogen == expected, nHydrogen <- 2
         * if nHydrogen != expected, expected <- nHydrogen
         */
        while (nHydrogen.compare_exchange_weak(expected, 2))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            expected = 2;
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        nHydrogen.fetch_add(1);
        conditionalReset();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        int expected = 1;
        /*
        * if nOxygen == expected, nOxygen <- 1
        * if nOxygen != expected, expected <- nOxygen
        */
        while (nOxygen.compare_exchange_weak(expected, 1))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            expected = 1;
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        nOxygen.fetch_add(1);
        conditionalReset();
    }
    
private:
    std::atomic<int> nHydrogen{0};
    std::atomic<int> nOxygen{0};
};
