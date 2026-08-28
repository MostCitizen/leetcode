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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        return hasPath(root, targetSum);
    }

    private boolean hasPath(TreeNode node, int sum){
        if(node.left == null && node.right == null) return sum - node.val == 0;
        else if(node.left == null) {
            return hasPath(node.right, sum - node.val);
        } else if(node.right == null){
            return hasPath(node.left, sum - node.val);
        } else {
            return hasPath(node.left, sum - node.val) || 
                hasPath(node.right, sum - node.val) ;
        }
    }
}