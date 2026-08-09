class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if(n == 1) return true;
        int far = 0;
        for(int i=0;i<n;i++){
            if(far < i) return false;
            far = Math.max(far, i + nums[i]);
        }
        return true;
    }
}