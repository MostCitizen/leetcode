function findMin(nums: number[]): number {
    var size:number = nums.length;
    if(size == 1) return nums[0];
    var left:number = 0, right:number = size-1;
    while(left <= right){
        var mid:number = Math.floor((right + left) / 2);
        if((mid == 0 && nums[mid] < nums[mid+1]) || 
            (mid > 0 && nums[mid] < nums[mid-1])) return nums[mid];
        else if(nums[mid] > nums[0] || nums[mid] > nums[size-1]){
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return nums[0];
};