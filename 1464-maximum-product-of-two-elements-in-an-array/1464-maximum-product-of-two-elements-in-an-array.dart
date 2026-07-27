class Solution {
  int maxProduct(List<int> nums) {
    nums.sort();
    int size = nums.length;
    return (nums[size-1] - 1) * (nums[size - 2] -1);
  }
}