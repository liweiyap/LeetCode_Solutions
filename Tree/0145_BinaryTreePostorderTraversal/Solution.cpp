// Runtime: 4 ms, faster than 56.53% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.

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
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> postorderVals;
        if (!root)
        {
            return postorderVals;
        }
        
        std::vector<TreeNode*> postorderNodes;
        std::stack<TreeNode*> s;
        s.push(root);
        TreeNode* node;
        while (!s.empty())
        {
            node = s.top();
            bool addRight = node->right && std::find(postorderNodes.begin(), postorderNodes.end(), node->right) == postorderNodes.end();
            bool addLeft = node->left && std::find(postorderNodes.begin(), postorderNodes.end(), node->left) == postorderNodes.end();
            if (addRight)
            {
                s.push(node->right);
            }
            if (addLeft)
            {
                s.push(node->left);
            }
            if (!addRight && !addLeft)
            {
                postorderNodes.push_back(node);
                s.pop();
            }
        }
        
        for (TreeNode* node : postorderNodes)
        {
            postorderVals.push_back(node->val);
        }
        
        return postorderVals;
    }
};
