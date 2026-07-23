class Solution {
  int findMin(List<int> nums) {
    if(nums.length == 1) return nums[0];
    int l = 0, r = nums.length-1;
    while(l<=r){
        int mid = (r+l)~/2;
        if(mid == 0){
            return nums[mid] < nums[mid+1] ? nums[mid] : nums[mid+1];
        }
        else if(nums[0] > nums[mid] && nums[mid] < nums[mid-1]){
            return nums[mid];
        }
        else if(nums[mid] > nums[0]){
            l = mid + 1;
        }
        else {
            r = mid-1;
        }
    }
    return nums[0];
  }
}