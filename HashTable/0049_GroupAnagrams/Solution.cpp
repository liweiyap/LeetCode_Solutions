// Runtime: 28 ms, faster than 88.55% of C++ online submissions for Group Anagrams.
// Memory Usage: 17.7 MB, less than 96.97% of C++ online submissions for Group Anagrams.

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::vector<std::vector<std::string>> output;
        std::unordered_map<std::string, std::vector<string>> dict;
        
        for (const auto& str : strs)
        {
            std::string strCopy = str;
            std::sort(strCopy.begin(), strCopy.end());
            dict[strCopy].push_back(str);
        }
        
        output.reserve(dict.size());
        for (auto& entry : dict)
        {
            output.push_back(std::move(entry.second));
        }
        return output;
    }
};
