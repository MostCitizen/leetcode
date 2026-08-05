class Solution {
    public int[] searchRange(int[] nums, int target) {
        return new int[] {first(nums, target), end(nums, target)};
    }

    private int first(int[] nums, int target){
        int left = 0, right = nums.length - 1;
        int res = -1;
        while(left <= right){
            int mid = (right + left) / 2;
            if(nums[mid] == target){
                res = mid;
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return res;
    }

    private int end(int[] nums, int target){
        int left = 0, right = nums.length - 1;
        int res = -1;
        while(left <= right){
            int mid = (right + left) / 2;
            if(nums[mid] == target){
                res = mid;
                left = mid + 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return res;
    }
}