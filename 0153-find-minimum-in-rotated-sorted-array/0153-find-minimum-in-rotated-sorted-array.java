class Solution {
    public int findMin(int[] nums) {
        int size = nums.length;
        if(size == 1) return nums[0];
        int left = 0, right = size-1;
        while(left <= right){
            int mid = (right + left) / 2;
            if((mid == 0 && nums[mid] < nums[mid+1]) || 
                (mid > 0 && nums[mid] < nums[mid-1])) return nums[mid];
            else if(nums[mid] < nums[0] || nums[mid] < nums[nums.length-1]){
                right = mid -1;
            }else {
                left = mid + 1;
            }
        }
        return nums[0];
    }
}