// Runtime: 20 ms, faster than 44.35% of C++ online submissions for Valid Anagram.
// Memory Usage: 9.6 MB, less than 49.25% of C++ online submissions for Valid Anagram.

#include <unordered_map>
#include <string>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::unordered_map<char, int> dict;
        for (auto strIt = s.begin(); strIt != s.end(); ++strIt)
        {
            ++dict[*strIt];
        }
        for (auto strIt = t.begin(); strIt != t.end(); ++strIt)
        {
            if (--dict[*strIt] < 0)
            {
                return false;
            }
            if (dict[*strIt] == 0)
            {
                dict.erase(*strIt);
            }
        }
        return dict.empty();
    }
};
