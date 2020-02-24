// Runtime: 4 ms, faster than 98.36% of C++ online submissions for Subsets.
// Memory Usage: 9.3 MB, less than 57.63% of C++ online submissions for Subsets.

#include <vector>
#include <cmath>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> powerSets;
        int powerSetSize = std::pow(2, nums.size());
        for (int i = 0; i < powerSetSize; ++i)
        {
            std::vector<int> powerSet;
            for (int j = 0; j < nums.size(); ++j)
            {
                int bitIdx = 1 << j;
                if ((i & bitIdx) != 0)
                {
                    powerSet.push_back(nums[j]);
                }
            }
            powerSets.push_back(powerSet);
        }
        return powerSets;
    }
};
