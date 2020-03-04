// Runtime: 8 ms, faster than 98.43% of C++ online submissions for Single Number.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Single Number.

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        int val = 0;
        for (int num : nums)
        {
            val ^= num;
        }
        return val;
    }
};
