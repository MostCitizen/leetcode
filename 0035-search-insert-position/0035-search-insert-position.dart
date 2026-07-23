class Solution {
  int searchInsert(List<int> nums, int target) {
    int l = 0, r = nums.length-1;
    while(l <= r){
        int mid = (r + l) ~/2;
        if(nums[mid] <= target && (mid+1 == nums.length || nums[mid+1] > target)){
            return nums[mid] == target ? mid : mid+1;
        }
        else if(nums[mid] < target){
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return 0;
  }
}