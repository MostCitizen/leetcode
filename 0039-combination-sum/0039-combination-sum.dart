class Solution {
  List<List<int>> combinationSum(List<int> candidates, int target) {
    List<List<int>> res = [];
    solve(res, candidates, target, 0, [], 0);
    return res;
  }

  void solve(List<List<int>> res, List<int> candidates, int target, int sum, List<int> list, int index){
    if(index >= candidates.length || target < sum) return;
    if(target == sum){
        res.add(List.of(list));
        return;
    }
    sum+=candidates[index];
    list.add(candidates[index]);
    solve(res, candidates, target, sum, list, index);
    sum-=candidates[index];
    list.remove(candidates[index]);
    solve(res, candidates, target, sum, list, index+1);
  }
}