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
    public TreeNode sortedArrayToBST(int[] nums) {
        int size = nums.length;
        if(size == 0) return null;
        int left = 0, right = size-1;
        int mid = (right+left) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = sortedArrayToBST(Arrays.copyOfRange(nums, left, mid));
        node.right = sortedArrayToBST(Arrays.copyOfRange(nums, mid+1, size));
        return node;
    }
}