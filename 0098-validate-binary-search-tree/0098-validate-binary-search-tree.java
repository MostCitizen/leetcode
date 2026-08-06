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
class Solution {
    public boolean isValidBST(TreeNode root) {
        return find(root, Long.MAX_VALUE, Long.MIN_VALUE);
    }

    public boolean find(TreeNode root, double max, double min){
        if(root == null) return true;
        else if(root.val <= min || root.val >= max) return false;
        return find(root.left, root.val, min) && find(root.right, max, root.val);
    }
}