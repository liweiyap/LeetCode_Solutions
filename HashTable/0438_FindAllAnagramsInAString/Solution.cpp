// Runtime: 80 ms, faster than 16.14% of C++ online submissions for Find All Anagrams in a String.
// Memory Usage: 14.4 MB, less than 19.23% of C++ online submissions for Find All Anagrams in a String.

#include <unordered_map>
#include <string>

class Solution
{
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        std::vector<int> anagramIndices;
        if (s.size() < p.size())
        {
            return anagramIndices;
        }
        
        std::unordered_map<char, int> sDict;
        std::unordered_map<char, int> pDict;
        for (int idx = 0; idx < p.size(); ++idx)
        {
            ++sDict[s[idx]];
            ++pDict[p[idx]];
        }
        if (isAnagram(sDict, pDict))
        {
            anagramIndices.push_back(0);
        }
        
        for (int idx = 1; idx <= s.size()-p.size(); ++idx)
        {
            if (--sDict[s[idx-1]] <= 0)
            {
                sDict.erase(s[idx-1]);
            }
            ++sDict[s[idx+p.size()-1]];
            
            if (isAnagram(sDict, pDict))
            {
                anagramIndices.push_back(idx);
            }
        }
        
        return anagramIndices;
    }
    
    bool isAnagram(std::unordered_map<char, int>& sDict, std::unordered_map<char, int>& pDict)
    {
        for (auto kv : sDict)
        {
            if (pDict[kv.first] != kv.second)
            {
                return false;
            }
        }
        return true;
    }
};
