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
  bool isValidBST(TreeNode? root) {
    if(root == null) return true;
    return solve(root, double.infinity, double.negativeInfinity);
  }

  bool solve(TreeNode? root, double max, double min){
    if(root == null) return true;
    else if(root.val <= min || root.val >= max) return false;
    return solve(root.left, root.val.toDouble(), min) && solve(root.right, max, root.val.toDouble());
  }
}