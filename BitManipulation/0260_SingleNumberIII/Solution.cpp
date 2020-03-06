// Runtime: 12 ms, faster than 93.98% of C++ online submissions for Single Number III.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Single Number III.

#include <vector>

class Solution
{
public:
    std::vector<int> singleNumber(std::vector<int>& nums)
    {
        int ones = 0;
        for (int num : nums)
        {
            ones ^= num;
        }
        int lsb = ones & -ones;
        
        std::vector<int> output{0, 0};
        for (int num : nums)
        {
            if ((num & lsb) == 0)
            {
                output[0] ^= num;
            }
            else
            {
                output[1] ^= num;
            }
        }
        return output;
    }
};
