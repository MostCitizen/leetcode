class Solution {
  int subarraySum(List<int> nums, int k) {
    int total = 0;
    for(int i=0;i<nums.length;i++){
        total += sumList(nums, k, i);
    }
    return total;
  }
  int sumList(List<int> nums, int k, int index){
    int sum = 0;
    int count = 0;
    for(int i=index;i<nums.length;i++){
        sum += nums[i];
        if(sum == k) {
            count++;
        };
    }
    return count;
  }
}