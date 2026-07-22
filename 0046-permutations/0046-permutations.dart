class Solution {
  List<List<int>> permute(List<int> nums) {
    List<List<int>> res = [];
    solve(res, nums, []);
    return res;
  }
  void solve(List<List<int>> res, List<int> nums, List<int> list){
    if(nums.length == list.length){
        res.add(List.of(list));
        return;
    }
    for(int i=0;i<nums.length;i++){
        if(list.contains(nums[i])){
            continue;
        }
        list.add(nums[i]);
        solve(res, nums, list);
        list.removeLast();
    }
  }
}