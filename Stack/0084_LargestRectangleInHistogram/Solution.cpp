// Runtime: 16 ms, faster than 52.04% of C++ online submissions for Largest Rectangle in Histogram.
// Memory Usage: 10.8 MB, less than 37.14% of C++ online submissions for Largest Rectangle in Histogram.

#include <stack>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        int maxArea = 0;
        std::stack<std::pair<int,int>> s;
        for (int idx = 0; idx < heights.size(); ++idx)
        {
            int leftWall = idx;
            while (!s.empty() && heights[idx] < heights[s.top().first])
            {
                leftWall = s.top().second;
                maxArea = std::max(maxArea, (idx - leftWall) * heights[s.top().first]);
                s.pop();
            }
            s.push(std::make_pair(idx,leftWall));
        }
        
        while (!s.empty())
        {
            maxArea = std::max(maxArea, (static_cast<int>(heights.size()) - s.top().second) * heights[s.top().first]);
            s.pop();
        }
        
        return maxArea;
    }
};
