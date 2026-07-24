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
  void flatten(TreeNode? root) {
    if(root == null) return;
    TreeNode? cur = root.left;
    if(cur == null) {
        flatten(root.right);
        return;
    }
    TreeNode? temp = root.right;
    root.right = cur;
    root.left = null;
    while(cur!.right != null){
        cur = cur.right;
    }
    cur.right = temp;
    flatten(root.right);
  }
}