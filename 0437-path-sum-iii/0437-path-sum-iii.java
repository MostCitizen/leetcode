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
    int count = 0;
    public int pathSum(TreeNode root, int targetSum) {
        if(root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode cur = q.remove();
            sum(cur, targetSum, 0);
            if(cur.left != null) q.add(cur.left);
            if(cur.right != null) q.add(cur.right);
        }
        return count;
    }

    private void sum(TreeNode root, int targetSum, long sum){
        if(root == null) return;
        sum += root.val;
        if(sum == targetSum){
            count++;
        }
        sum(root.left, targetSum, sum);
        sum(root.right, targetSum, sum);
    }
}