// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
// Memory Usage: 6.6 MB, less than 32.93% of C++ online submissions for Decode String.

#include <stack>
#include <vector>
#include <string>
#include <cctype>

class Solution
{
public:
    std::string decodeString(std::string s)
    {
        int num = 0;
        
        for (auto s_it = s.begin(); s_it != s.end(); ++s_it)
        {
            if (isdigit(*s_it))
            {
                num = 10 * num + (*s_it - '0');
            }
            else if ( (*s_it == '[') || (isalpha(*s_it)) )
            {
                if (num != 0)
                {
                    repsStack.push(num);
                    num = 0;
                }
                
                std::string substr(1, *s_it);
                substrStack.push(substr);
            }
            else if (*s_it == ']')
            {
                std::vector<std::string> vec;
                while (substrStack.top() != "[")
                {
                    popSubstrToVec(vec);
                }
                substrStack.pop();  // pop the "["
                
                int reps = repsStack.top();
                repsStack.pop();

                std::string repSubstr;
                for (int rep = 0; rep < reps; ++rep)
                {
                    formSubStrFromVec(repSubstr, vec);
                }
                substrStack.push(repSubstr);
            }
        }
        
        std::vector<std::string> vec;
        while (!substrStack.empty())
        {
            popSubstrToVec(vec);
        }
        
        std::string output;
        formSubStrFromVec(output, vec);
        
        return output;
    }
    
private:
    std::stack<int> repsStack;
    std::stack<std::string> substrStack;
    
    void popSubstrToVec(std::vector<std::string>& vec)
    {
        if (substrStack.empty())
        {
            return;
        }
        
        const std::string& subStr = substrStack.top();
        vec.emplace_back(subStr);
        substrStack.pop();
    }
    
    void formSubStrFromVec(std::string& str, const std::vector<std::string>& vec)
    {
        for (auto v_it = vec.rbegin(); v_it != vec.rend(); ++v_it)
        {
            str += *v_it;
        }
    }
};
