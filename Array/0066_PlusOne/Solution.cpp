// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
// Memory Usage: 8.6 MB, less than 83.61% of C++ online submissions for Plus One.

#include <vector>

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        if (digits[digits.size()-1] == 9)
        {
            if (digits.size() >= 2)
            {
                digits[digits.size()-1] = 0;
                ++digits[digits.size()-2];

                for (int carry = digits.size()-2; carry >= 1; --carry)
                {
                    if (digits[carry] >= 10)
                    {
                        digits[carry] -= 10;
                        ++digits[carry-1];
                    }
                }
            }
            else
            {
                ++digits[digits.size()-1];
            }
            
            if (digits[0] == 10)
            {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }
        }
        else
        {
            ++digits[digits.size()-1];
        }
        return digits;
    }
};
