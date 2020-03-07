// Runtime: 36 ms, faster than 97.73% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Product of Array Except Self.

#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        std::vector<int> products(nums.size(), 1);
        
        int tmp = 1;
        for (int i = 0; i < products.size(); ++i)
        {
            products[i] *= tmp;
            tmp *= nums[i];
        }
        
        tmp = 1;
        for (int i = products.size() - 1; i >= 0; --i)
        {
            products[i] *= tmp;
            tmp *= nums[i];
        }
        
        return products;
    }
};
