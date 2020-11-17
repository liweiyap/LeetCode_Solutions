// Runtime: 632 ms, faster than 8.70% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 22.4 MB, less than 7.87% of C++ online submissions for Validate Binary Search Tree.

#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }
        
        std::vector<TreeNode*> inOrderTraversalNodes;
        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* node;
        while (!nodeStack.empty())
        {
            node = nodeStack.top();
            
            if ( (node->left) &&
                 (std::find(inOrderTraversalNodes.begin(), inOrderTraversalNodes.end(), node->left) == inOrderTraversalNodes.end()) )
            {
                nodeStack.push(node->left);
            }
            else
            {
                nodeStack.pop();
                inOrderTraversalNodes.push_back(node);
                
                if ( (node->right) &&
                     (std::find(inOrderTraversalNodes.begin(), inOrderTraversalNodes.end(), node->right) == inOrderTraversalNodes.end()) )
                {
                    nodeStack.push(node->right);
                }
            }
        }
        
        if (inOrderTraversalNodes.size() == 1)
        {
            return true;
        }
        
        for (auto nodeIt = inOrderTraversalNodes.begin();
             nodeIt != std::prev(inOrderTraversalNodes.end(), 1);
             ++nodeIt)
        {
            if ((*nodeIt)->val >= (*(nodeIt+1))->val)
            {
                return false;
            }
        }
        
        return true;
    }
};
