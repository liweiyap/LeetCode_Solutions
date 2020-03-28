// Runtime: 4 ms, faster than 94.65% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Trapping Rain Water.

#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        if (height.size() == 0)
        {
            return 0;
        }
        
        int waterVolume = 0;
        std::stack<int> stack_;
        int lastPopped;
        for (int idx = 0; idx < height.size(); ++idx)
        {
            while (!stack_.empty() && height[idx] > height[stack_.top()])
            {
                lastPopped = stack_.top();
                stack_.pop();
                if (!stack_.empty())
                {
                    waterVolume += (idx - stack_.top() - 1) * (std::min(height[idx], height[stack_.top()]) - height[lastPopped]);
                }
            }
            stack_.push(idx);
        }
        return waterVolume;
    }
};
