/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class Solution {
  List<int> rightSideView(TreeNode? root) {
    List<List<int>> res = [];
    solve(res, root, 0);
    List<int> ans = [];
    for(int i=0;i<res.length;i++){
        ans.add(res[i][res[i].length-1]);
    }
    return ans;
  }
  void solve(List<List<int>> res, TreeNode? root, int index){
    if(root == null) return;
    if(res.length <= index) res.add([]);
    res[index].add(root.val);
    solve(res, root.left, index+1);
    solve(res, root.right, index+1);
  }
}