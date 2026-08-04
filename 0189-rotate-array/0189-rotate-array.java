class Solution {
    public void rotate(int[] nums, int k) {
        int size = nums.length;
        k = k % size;
        for(int i=0;i<k/2;i++){
            int temp = nums[size-k+i];
            nums[size-k+i] = nums[size-1-i];
            nums[size-1-i] = temp;
        }
        for(int i=0;i<(size-k)/2;i++){
            int temp = nums[i];
            nums[i] = nums[size-k-1-i];
            nums[size-k-1-i] = temp;
        }
        for(int i=0;i<size/2;i++){
            int temp = nums[i];
            nums[i] = nums[size-1-i];
            nums[size-1-i] = temp;
        }
    }
}