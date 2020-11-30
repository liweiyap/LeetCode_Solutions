// Runtime: 1104 ms, faster than 5.03% of C++ online submissions for Combination Sum.
// Memory Usage: 114.6 MB, less than 5.01% of C++ online submissions for Combination Sum.

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        std::vector<int> combination;
        backtracker(candidates, combination, 0, target);
        return combinations;
    }
    
private:
    void backtracker(std::vector<int>& candidates, std::vector<int>& combination, int current_sum, int target)
    {
        if (current_sum == target)
        {
            std::sort(combination.begin(), combination.end());
            if (std::find(combinations.begin(), combinations.end(), combination) == combinations.end())
            {
                combinations.push_back(combination);
            }
            return;
        }
        
        if (current_sum > target)
        {
            return;
        }
        
        for (int idx = 0; idx < candidates.size(); ++idx)
        {
            std::vector<int> combination_orig = combination;
            combination.push_back(candidates[idx]);
            backtracker(candidates, combination, current_sum+candidates[idx], target);
            combination = combination_orig;
        }
    }
    
    std::vector<std::vector<int>> combinations;
};
