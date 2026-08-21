function jump(nums: number[]): number {
    var res = 0
    var cur = 0, far = 0
    while(far < nums.length-1){
        let max = 0
        for(var i=cur;i<=far;i++){
            max = Math.max(max, i + nums[i]);
        }
        cur = far + 1
        far = max
        res++
    }
    return res
};