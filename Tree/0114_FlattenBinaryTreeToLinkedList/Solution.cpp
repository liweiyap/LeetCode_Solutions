// Runtime: 12 ms, faster than 27.52% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 11.3 MB, less than 8.33% of C++ online submissions for Flatten Binary Tree to Linked List.

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
    void flatten(TreeNode* root)
    {
        TreeNode* node = root;
        while (node)
        {
            if (node->left)
            {
                if (node->right)
                {
                    TreeNode* tmp = node->left;
                    while (tmp->right)
                    {
                        tmp = tmp->right;
                    }
                    tmp->right = node->right;
                }
                node->right = node->left;
                node->left = nullptr;
            }
            node = node->right;
        }
    }
};
