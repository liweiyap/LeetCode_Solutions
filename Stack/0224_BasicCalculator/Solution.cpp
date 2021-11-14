// Runtime: 4 ms, faster than 98.80% of C++ online submissions for Basic Calculator.
// Memory Usage: 8.2 MB, less than 44.31% of C++ online submissions for Basic Calculator.

#include <stack>
#include <string>
#include <cctype>

class Solution
{
public:
    int calculate(std::string s)
    {
        reset();

        for (auto s_it = s.begin(); s_it != s.end(); ++s_it)
        {
            if (isdigit(*s_it))
            {
                num_tmp_ = 10 * num_tmp_ + (*s_it - '0');
            }
            else if (*s_it == '+')
            {
                output_ += sign_ * num_tmp_;
                num_tmp_ = 0;

                sign_ = sign::positive;
            }
            else if (*s_it == '-')
            {
                output_ += sign_ * num_tmp_;
                num_tmp_ = 0;

                sign_ = sign::negative;
            }
            else if (*s_it == '(')
            {
                num_stack_.push(output_);
                sign_stack_.push(sign_);

                reset();
            }
            else if (*s_it == ')')
            {
                output_ += sign_* num_tmp_;
                num_tmp_ = 0;

                sign_ = sign::positive;

                output_ *= sign_stack_.top();
                sign_stack_.pop();

                output_ += num_stack_.top();
                num_stack_.pop();
            }
        }

        output_ += sign_* num_tmp_;

        return output_;
    }

private:
    int num_tmp_ = 0;

    int output_ = 0;

    enum sign {
        positive = 1,
        negative = -1
    };

    sign sign_ = sign::positive;

    std::stack<int> num_stack_;
    std::stack<sign> sign_stack_;

    void reset()
    {
        output_ = 0;
        sign_ = sign::positive;
        
        num_tmp_ = 0;
    }
};
