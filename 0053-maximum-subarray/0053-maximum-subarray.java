class Solution {
    public int maxSubArray(int[] nums) {
        int m = -Integer.MAX_VALUE;
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            if(sum < 0) sum = 0;
            sum += nums[i];
            m = Math.max(m, sum);
        }
        return m;
    }
}