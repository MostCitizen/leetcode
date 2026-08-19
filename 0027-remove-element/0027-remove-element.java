class Solution {
    public int removeElement(int[] nums, int val) {
        int size = nums.length;
        int left = 0, right = size-1;
        int count = 0;
        while(left <= right){
            if(nums[left] == val){
                count++;
                while(left != right && nums[right] == val){
                    right--;
                    count++;
                }
                nums[left] = nums[right];
                right--;
                left++;
            }else{
                left++;
            }
        }
        return size - count;
    }
}