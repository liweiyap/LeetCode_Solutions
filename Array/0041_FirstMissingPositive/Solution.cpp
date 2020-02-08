// Runtime: 4 ms, faster than 66.43% of C++ online submissions for First Missing Positive.
// Memory Usage: 8.7 MB, less than 80.00% of C++ online submissions for First Missing Positive.

#include <vector>
#include <algorithm>

class Solution
{
public:
    // put each number in its right place, e.g. when we find 5, then swap it with A[4].
    int firstMissingPositive(std::vector<int>& nums)
    {
        size_t idx = 0;
        while (idx < nums.size())
        {
            if (nums[idx] > 0 && nums[idx] <= nums.size() && nums[idx] != nums[nums[idx]-1])
            {
                std::swap(nums[idx], nums[nums[idx]-1]);
            }
            else
            {
                ++idx;
            }
        }
        
        for (int idx = 0; idx < nums.size(); ++idx)
        {
            if (nums[idx] != idx+1)
            {
                return idx+1;
            }
        }
        return nums.size()+1;
    }
};
