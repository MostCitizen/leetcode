class Solution {
  int search(List<int> nums, int target) {
    int l = 0, r = nums.length-1;
    while(l <= r){
        int m = (r + l) ~/ 2;
        if(nums[m] == target){
            return m;
        }
        else if(nums[m] < nums[0]){
            if(target > nums[m]){
                if(target < nums[0]) l = m+1;
                else r = m-1;
            }
            else {
                r = m-1;
            }
        }
        else {
            if(target < nums[m]){
                if(target < nums[0]) l = m+1;
                else r=m-1;
            }
            else {
                l = m+1;
            }
        }
    }
    return -1;
  }
}