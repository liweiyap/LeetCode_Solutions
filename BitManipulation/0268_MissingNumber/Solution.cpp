// Runtime: 20 ms, faster than 94.89% of C++ online submissions for Missing Number.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Missing Number.

#include <vector>

class Solution
{
public:
    int missingNumber(std::vector<int>& nums)
    {
        int val = 0;
        for (int num : nums)
        {
            val ^= num;
        }
        return val ^= computeXOR(nums.size());
    }
    
    int computeXOR(int num)
    {
        if (num % 4 == 0)
        {
            return num;
        }
        else if (num % 4 == 1)
        {
            return 1;
        }
        else if (num % 4 == 2)
        {
            return num + 1;
        }
        else
        {
            return 0;
        }
    }
};
