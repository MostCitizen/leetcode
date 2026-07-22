class Solution {
  List<String> generateParenthesis(int n) {
    List<String> res = [];
    solve(res, n, 0, 0, "");
    return res;
  }
  void solve(List<String> res, int n, int l, int r, String s){
    if(n == l && n == r){
        res.add(s);
        return;
    }
    if(n > l)
        solve(res, n, l+1, r, s+"(");
    if(l > r)
        solve(res, n, l, r+1, s+")");
  }
}