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
    public int kthSmallest(TreeNode root, int k) {
        List<Integer> list = new ArrayList<>();
        build(root, list, k);
        return list.get(list.size() -1);
    }

    private void build(TreeNode node, List<Integer> list, int k){
        if(node == null) return;
        build(node.left, list, k);
        if(list.size() < k) {
            list.add(node.val);
        }else {
            return;
        }
        build(node.right, list, k);
    }
}