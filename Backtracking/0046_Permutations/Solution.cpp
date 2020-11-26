// Runtime: 4 ms, faster than 81.85% of C++ online submissions for Permutations.
// Memory Usage: 8.4 MB, less than 35.61% of C++ online submissions for Permutations.

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        backtracker(nums, 0);
        return permutations;
    }
    
private:
    // recursion
    void backtracker(std::vector<int>& nums, int start)
    {
        if (start == nums.size()-1)
        {
            permutations.push_back(nums);
            return;
        }
        
        for (int idx = start; idx < nums.size(); ++idx)
        {
            std::swap(nums[start], nums[idx]);
            backtracker(nums, start+1);
            std::swap(nums[start], nums[idx]);
        }
    }
    
    std::vector<std::vector<int>> permutations;
};
