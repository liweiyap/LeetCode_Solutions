// Runtime: 8 ms, faster than 67.65% of C++ online submissions for Multiply Strings.
// Memory Usage: 10 MB, less than 23.08% of C++ online submissions for Multiply Strings.

#include <string>
#include <vector>

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        std::string output;
        std::vector<int> outputVec(num1.size()+num2.size(), 0);
        
        for (int s_idx = num1.size()-1; s_idx >= 0; --s_idx)
        {
            int s_ch = num1[s_idx] - '0';
            int o_idx = (num1.size()-1) - s_idx;
            int carry = 0;
            for (int l_idx = num2.size()-1; l_idx >= 0; --l_idx)
            {
                int l_ch = num2[l_idx] - '0';
                int mul = l_ch * s_ch;
                mul += carry;
                outputVec[o_idx] += mul;
                carry = outputVec[o_idx] / 10;
                if (carry > 0)
                {
                    outputVec[o_idx] %= 10;
                }
                ++o_idx;
            }
            if (carry != 0)
            {
                outputVec[o_idx] = carry;
            }
        }
        
        int end = outputVec.size() - 1;
        while (end >= 0 && outputVec[end] == 0)
        {
            --end;
        }
        if (end == -1)  // then at least one of the numbers is 0
        {
            return "0";
        }
        
        for (int v_idx = 0; v_idx <= end; ++v_idx)
        {
            output = std::to_string(outputVec[v_idx]) + output;
        }
        return output;
    }
};
