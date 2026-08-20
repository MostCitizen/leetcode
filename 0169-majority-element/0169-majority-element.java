class Solution {
    public int majorityElement(int[] nums) {
        int size = nums.length;
        int count = 0;
        int current = 0;
        for(int num : nums){
            if(count == 0){
                current = num;
            }
            if(current == num) count++;
            else count--;
        }
        return current;
    }
}