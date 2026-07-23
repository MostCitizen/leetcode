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
  bool isSymmetric(TreeNode? root) {
    if(root == null) return true;
    else if(root.left == null && root.right == null) return true;
    else if(root.left == null || root.right == null) return false; 
    return solve(root.left, root.right);
  }
  bool solve(TreeNode? left, TreeNode? right){
    if(left == null && right == null) return true;
    else if (left == null || right == null) return false;
    else if(left.val != right.val) return false;
    return solve(left.left, right.right) && solve(right.left, left.right);
  }
}