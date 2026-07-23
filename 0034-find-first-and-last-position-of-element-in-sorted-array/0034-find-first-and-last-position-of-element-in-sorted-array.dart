class Solution {
  List<int> searchRange(List<int> nums, int target) {
    if(nums.length == 0) return [-1, -1];
    List<int> res = [];
    int l = 0, r = nums.length -1;
    while(l <= r){
        int mid = (r + l) ~/ 2;
        if(nums[mid] == target){
            int left=mid, right=mid;
            for(;left>=0 && nums[left]==target;left--);
            for(;right<nums.length && nums[right]==target;right++);
            left++;
            right--;
            return [left, right];
        } else if(nums[mid] > target){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return [-1, -1];
  }
}