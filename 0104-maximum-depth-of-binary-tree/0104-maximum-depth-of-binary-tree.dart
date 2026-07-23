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
  int maxDepth(TreeNode? root) {
    if(root == null) return 0;
    int m = 0;
    Queue<TreeNode> q = Queue();
    q.add(root);

    while(q.isNotEmpty){
        int size = q.length;
        for(int i=0;i<size;i++){
            TreeNode cur = q.removeFirst();
            if(cur.left != null) q.add(cur.left!);
            if(cur.right != null) q.add(cur.right!);
        }
        m++;
    }
    return m;
    
  }
}