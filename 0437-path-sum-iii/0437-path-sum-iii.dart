/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */

import 'dart:collection';
class Solution {
    int count = 0;
  int pathSum(TreeNode? root, int targetSum) {
    if(root == null) return 0;
    Queue<TreeNode> q = Queue();
    q.add(root);
    while(q.isNotEmpty){
        final cur = q.removeFirst();
        find(cur, targetSum, 0);
        if(cur.left != null) q.add(cur.left!);
        if(cur.right != null) q.add(cur.right!);
    }
    return count;
  }
  void find(TreeNode? root, int targetSum, int sum){
    if(root == null) return;
    sum += root.val;
    if(targetSum == sum){
        count++;
    }
    find(root.left, targetSum, sum);
    find(root.right, targetSum, sum);
  }
}