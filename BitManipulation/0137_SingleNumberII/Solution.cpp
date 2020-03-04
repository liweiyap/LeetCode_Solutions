// Runtime: 8 ms, faster than 98.55% of C++ online submissions for Single Number II.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Single Number II.

#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        int ones = 0;
        int twos = 0;
        int commonBitMask;
        for (int num : nums)
        {
            twos |= (ones & num);
            ones ^= num;
            commonBitMask = ~(ones & twos);
            ones &= commonBitMask;
            twos &= commonBitMask;
        }
        return ones;
    }
};
