// Runtime: 212 ms, faster than 51.27% of C++ online submissions for Building H2O.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Building H2O.

#include <mutex>
#include <condition_variable>

class H2O
{
public:
    H2O(){}
    
    void conditionalReset()
    {
        if (n_hydrogen == 2 && n_oxygen == 1)
        {
            n_hydrogen = 0;
            n_oxygen = 0;
        }
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        std::unique_lock<std::mutex> guard(m);
        cond.wait(guard, [&]{return n_hydrogen != 2;});
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++n_hydrogen;
        conditionalReset();
        cond.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        std::unique_lock<std::mutex> guard(m);
        cond.wait(guard, [&]{return n_oxygen != 1;});
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++n_oxygen;
        conditionalReset();
        cond.notify_all();
    }
