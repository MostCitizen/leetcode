function canJump(nums: number[]): boolean {
    var jump = nums[0];
    for(var i=0;i<nums.length;i++){
        if(jump < i) return false;
        jump = Math.max(jump, i + nums[i]);
    }
    return true;
};