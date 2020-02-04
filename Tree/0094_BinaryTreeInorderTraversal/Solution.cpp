// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.2 MB, less than 89.00% of C++ online submissions for Binary Tree Inorder Traversal.

#include <vector>
#include <stack>
#include <algorithm>

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
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> inorderVals;
        if (!root)
        {
            return inorderVals;
        }
        
        std::vector<TreeNode*> inorderNodes;
        std::stack<TreeNode*> s;
        s.push(root);
        TreeNode* node;
        
        while (!s.empty())
        {
            node = s.top();
            if (node->left &&
                std::find(inorderNodes.begin(), inorderNodes.end(), node->left) == inorderNodes.end())
            {
                s.push(node->left);
            }
            else
            {
                s.pop();
                inorderNodes.push_back(node);
                
                if (node->right &&
                std::find(inorderNodes.begin(), inorderNodes.end(), node->right) == inorderNodes.end())
                {
                    s.push(node->right);
                }
            }
        }
        
        for (TreeNode* node : inorderNodes)
        {
            inorderVals.push_back(node->val);
        }
        
        return inorderVals;
    }
};
