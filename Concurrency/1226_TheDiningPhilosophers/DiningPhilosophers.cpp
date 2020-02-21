// Runtime: 144 ms, faster than 87.87% of C++ online submissions for The Dining Philosophers.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for The Dining Philosophers.

#include <mutex>

/*
                Philosopher 0
            Fork 4          Fork 0
    Philosopher 4               Philosopher 1
      Fork 3                Fork 1
        Philosopher 3   Philosopher 2
                   Fork 2
 */

class DiningPhilosophers
{
public:
    DiningPhilosophers(){}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {
        int leftFork = philosopher;
        int rightFork = (philosopher + 4) % 5;
        
        // introduce order to forks
        // bundle forks together so that >1 philosopher can eat at any one time (faster)
        int firstFork = (philosopher % 2 == 0) ? leftFork : rightFork;
        int secondFork = (philosopher % 2 == 0) ? rightFork : leftFork;
        
        std::unique_lock<std::mutex> firstGuard(mutexArray[firstFork]);
        std::unique_lock<std::mutex> secondGuard(mutexArray[secondFork]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
    
private:
    std::mutex mutexArray[5];
};
