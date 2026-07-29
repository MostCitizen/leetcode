class Solution {
  int longestConsecutive(List<int> nums) {
    int size = nums.length;
    if(size <= 1) return size;
    Set<int> s = nums.toSet();
    int m = 0;
    for(int num in s){
        if(s.contains(num-1)) continue;
        int count = 1;
        int cur = num;
        while(s.contains(cur+1)){
            cur += 1;
            count += 1;
        }
        m = max(m, count);
    }
    return m;
  }
}