// Runtime: 176 ms, faster than 97.94% of C++ online submissions for Daily Temperatures.
// Memory Usage: 16.2 MB, less than 64.00% of C++ online submissions for Daily Temperatures.

#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& T)
    {
        std::vector<int> waitingTimes(T.size(), 0);
        std::stack<int> s;
        
        for (size_t currIdx = 0; currIdx < T.size(); ++currIdx)
        {
            while (!s.empty() && T[currIdx] > T[s.top()])
            {
                waitingTimes[s.top()] = currIdx - s.top();
                s.pop();
            }
            
            s.push(currIdx);
        }
        
        return waitingTimes;
    }
};
