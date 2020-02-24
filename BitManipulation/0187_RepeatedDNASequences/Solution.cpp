// Runtime: 36 ms, faster than 93.88% of C++ online submissions for Repeated DNA Sequences.
// Memory Usage: 16.7 MB, less than 100.00% of C++ online submissions for Repeated DNA Sequences.

#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s)
    {
        std::vector<std::string> output;
        std::unordered_map<int, int> occurrences;
        
        int sub_s = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char nucleotide = s[i];
            int nucleotideInt = convertCharToNumeric(nucleotide);
            assert(nucleotideInt != 4);
            
            sub_s <<= 2;
            sub_s |= nucleotideInt;
            sub_s &= 0xfffff;  // == 20 bits of 1 (fixed window length of 10 nucleotides or 20 digits)
            
            if (i < 9)
            {
                continue;
            }
            
            if (occurrences[sub_s] == 1)
            {
                output.push_back(s.substr(i-9, 10));
            }
            ++occurrences[sub_s];
        }
        
        return output;
    }
    
    int convertCharToNumeric(char nucleotide)
    {
        if (nucleotide == 'A')
        {
            return 0;
        }
        else if (nucleotide == 'T')
        {
            return 1;
        }
        else if (nucleotide == 'C')
        {
            return 2;
        }
        else if (nucleotide == 'G')
        {
            return 3;
        }
        return 4;
    }
};
