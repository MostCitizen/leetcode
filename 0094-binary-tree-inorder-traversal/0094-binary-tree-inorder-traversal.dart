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
    List<int> res = [];
  List<int> inorderTraversal(TreeNode? root) {
    if(root == null) return res;
    inorderTraversal(root.left);
    res.add(root.val);
    inorderTraversal(root.right);
    
    return res;
  }
}