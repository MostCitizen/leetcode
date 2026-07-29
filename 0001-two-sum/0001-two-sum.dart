class Solution {
  List<int> twoSum(List<int> nums, int target) {
    Map<int, int> map = Map();
    for(int i=0;i<nums.length;i++){
        int re = target - nums[i];
        if(map.containsKey(re)){
            return [map[re]!, i];
        }
        map[nums[i]] = i;
    }
    return [];
  }
}