class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0, right = nums.length-1;
        if(nums[left] >= target) return left;
        else if(nums[right] <= target) return nums[right] == target ? right : right+1;
        while(left <= right){
            int mid = (right + left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target && target < nums[mid+1]) return mid+1;
            else if(nums[mid] > target){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
}