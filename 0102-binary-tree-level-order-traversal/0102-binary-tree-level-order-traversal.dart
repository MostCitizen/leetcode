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
  List<List<int>> levelOrder(TreeNode? root) {
    if(root == null) return [];
    List<List<int>> res = [];
    Queue<TreeNode> q = Queue();
    q.add(root);
    while(q.isNotEmpty){
        int size = q.length;
        List<int> temp = [];
        for(int i=0;i<size;i++){
            TreeNode cur = q.removeFirst();
            temp.add(cur.val);
            if(cur.left != null) q.add(cur.left!);
            if(cur.right != null) q.add(cur.right!);
        }
        res.add(List.of(temp));
    }
    return res;
  }
}