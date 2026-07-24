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
  int kthSmallest(TreeNode? root, int k) {
    if(root == null) return -1;
    List<int> list = [];
    Queue<TreeNode> q = Queue();
    q.add(root);
    while(q.isNotEmpty){
        TreeNode cur = q.removeFirst();
        list.add(cur.val);
        if(cur.left != null) q.add(cur.left!);
        if(cur.right != null) q.add(cur.right!);
    }
    list.sort();
    return list[k-1];
  }
}