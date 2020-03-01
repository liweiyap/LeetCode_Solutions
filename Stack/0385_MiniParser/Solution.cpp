// Runtime: 16 ms, faster than 84.65% of C++ online submissions for Mini Parser.
// Memory Usage: 13.4 MB, less than 40.00% of C++ online submissions for Mini Parser.

#include <stack>
#include <vector>
#include <string>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
public:
    NestedInteger deserialize(std::string s)
    {
        std::stack<NestedInteger> stk;
        for (auto it = 0; it < s.size(); ++it)
        {
            if (s[it] == '[')
            {
                stk.push(NestedInteger());
            }
            else if (s[it] == '-' || isdigit(s[it]))
            {
                auto start = it;
                while (it+1 < s.size() && isdigit(s[it+1]))
                {
                    ++it;
                }
                int currVal = std::stoi(s.substr(start, it - start + 1));
                if (!stk.empty())
                {
                    stk.top().add(NestedInteger(currVal));
                }
                else
                {
                    return NestedInteger(currVal);
                }
            }
            else if (s[it] == ']')
            {
                NestedInteger currList = stk.top();
                stk.pop();
                if (!stk.empty())
                {
                    stk.top().add(currList);
                }
                else
                {
                    return currList;
                }
            }
        }
        
        return stk.top();
    }
    
    void printRecursive(NestedInteger ni)
    {
        if (ni.isInteger())
        {
            std::cout << ni.getInteger() << "\n";
        }
        else
        {
            std::vector<NestedInteger>& ni_vec = ni.getList();
            for (NestedInteger tmp_ni : ni_vec)
            {
                printRecursive(tmp_ni);
            }
        }
    }
};
