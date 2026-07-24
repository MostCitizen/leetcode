/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class Solution {
  TreeNode? invertTree(TreeNode? root) {
    if(root == null) return root;
    TreeNode? temp = root.left;
    root.left = root.right;
    root.right = temp;
    root.left = invertTree(root.left);
    root.right = invertTree(root.right);
    return root;
  }
}