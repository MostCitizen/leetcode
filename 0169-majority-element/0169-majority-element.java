class Solution {
    public int majorityElement(int[] nums) {
        int size = nums.length;
        int count = 0;
        Arrays.sort(nums);
        for(int i=0;i<size-1;i++){
            if(nums[i] != nums[i+1]){
                if(count >= size/2) return nums[i];
                count = 0;
            }
            count++;
        }
        return nums[size-1];
    }
}