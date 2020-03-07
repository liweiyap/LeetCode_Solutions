// Runtime: 4 ms, faster than 57.45% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.

#include <vector>
#include <stack>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> output;
        if (!root)
        {
            return output;
        }
        
        std::stack<TreeNode*> s;
        s.push(root);
        TreeNode* node;
        
        while (!s.empty())
        {
            node = s.top();
            output.push_back(node->val);
            s.pop();
            
            if (node->right)
            {
                s.push(node->right);
            }
            
            if (node->left)
            {
                s.push(node->left);
            }
        }
        
        return output;
    }
};
