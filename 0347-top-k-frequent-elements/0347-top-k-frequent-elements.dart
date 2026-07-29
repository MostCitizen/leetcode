class Solution {
  List<int> topKFrequent(List<int> nums, int k) {
    Map<int, int> map = Map();
    for(int i=0;i<nums.length;i++){
        map.update(nums[i], (val) => val + 1, ifAbsent: () => 1);
    }
    final temp = Map.fromEntries(
        map.entries.toList()..sort((a, b) => b.value.compareTo(a.value))
    );
    List<int> res = [];
    int count = 0;
    for(var el in temp.entries){
        if(count == k) break;
        count++;
        res.add(el.key);
    }
    return res;
  }
}