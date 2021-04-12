// Runtime: 0 ms, faster than 100.00% of Java online submissions for Invert Binary Tree.
// Memory Usage: 36.2 MB, less than 86.58% of Java online submissions for Invert Binary Tree.

import java.util.Queue;
import java.util.LinkedList;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution
{
    public TreeNode invertTree(TreeNode root)
    {
        if (root == null)
        {
            return root;
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while (!queue.isEmpty())
        {
            TreeNode curr = queue.poll();
            TreeNode tmp = curr.left;
            curr.left = curr.right;
            curr.right = tmp;

            if (curr.left != null)
            {
                queue.add(curr.left);
            }

            if (curr.right != null)
            {
                queue.add(curr.right);
            }
        }

        return root;
    }
}