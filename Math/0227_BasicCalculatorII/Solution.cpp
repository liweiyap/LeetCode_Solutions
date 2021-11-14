// Runtime: 8 ms, faster than 89.72% of C++ online submissions for Basic Calculator II.
// Memory Usage: 7.7 MB, less than 97.29% of C++ online submissions for Basic Calculator II.

#include <string>
#include <cctype>
#include <cwctype>

class Solution
{
public:
    int calculate(std::string s)
    {
        for (auto s_it = s.begin(); s_it != s.end(); ++s_it)
        {
            if (isdigit(*s_it))
            {
                num_tmp_ = 10 * num_tmp_ + (*s_it - '0');
            }
            
            if ((!isdigit(*s_it) && !iswspace(*s_it)) || (s_it == std::prev(s.end())))
            {
                if (op_ == '+')
                {
                    output_ += num_tmp_prev_;
                    num_tmp_prev_ = num_tmp_;
                }
                else if (op_ == '-')
                {
                    output_ += num_tmp_prev_;
                    num_tmp_prev_ = -num_tmp_;
                }
                else if (op_ == '*')
                {
                    num_tmp_prev_ *= num_tmp_;
                }
                else if (op_ == '/')
                {
                    num_tmp_prev_ /= num_tmp_;
                }
                
                op_ = *s_it;
                num_tmp_ = 0;
            }
        }
        
        output_ += num_tmp_prev_;
        
        return output_;
    }
    
private:
    int num_tmp_ = 0;
    int num_tmp_prev_ = 0;
    
    int output_ = 0;
    
    char op_ = '+';
};
