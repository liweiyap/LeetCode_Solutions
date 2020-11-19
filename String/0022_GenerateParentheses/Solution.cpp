// Runtime: 4 ms, faster than 79.55% of C++ online submissions for Generate Parentheses.
// Memory Usage: 14.5 MB, less than 32.04% of C++ online submissions for Generate Parentheses.

#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int nPairs)
    {
        helper("", 0, 0, nPairs);
        return combinations;
    }
    
private:
    // recursion
    void helper(std::string str, int nOpen, int nClose, int nPairs)
    {
        if (nOpen == nPairs && nClose == nPairs)
        {
            combinations.push_back(str);
            return;
        }
        
        if (nOpen > nClose)
        {
            helper(str+")", nOpen, nClose+1, nPairs);
        }
        
        if (nOpen < nPairs)
        {
            helper(str+"(", nOpen+1, nClose, nPairs);
        }
    }
    
    std::vector<std::string> combinations;
};
