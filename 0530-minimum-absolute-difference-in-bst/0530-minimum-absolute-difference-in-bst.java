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
    int min = Integer.MAX_VALUE;
    TreeNode prev = null;
    public int getMinimumDifference(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        find(root);
        return min;
    }
    private void find(TreeNode node){
        if(node == null) return;
        find(node.left);
        if(prev != null){
            min = Math.min(min, Math.abs(node.val - prev.val));
        }
        prev = node;
        find(node.right);
    }
}