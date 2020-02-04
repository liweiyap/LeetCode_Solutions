// Runtime: 60 ms, faster than 25.98% of C++ online submissions for Counting Bits.
// Memory Usage: 9.5 MB, less than 82.93% of C++ online submissions for Counting Bits.

#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int num)
    {
        std::vector<int> binReps(num + 1);
        binReps[0] = 0;
        for (int i = 1; i <= num; ++i)
        {
            // x & (x - 1) always equals x with the LSB erased (changed from 1 to 0)
            binReps[i] = binReps[i & (i-1)] + 1;
        }
        return binReps;
    }
};
