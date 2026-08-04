class Solution {
    public int[] productExceptSelf(int[] nums) {
        int size = nums.length;
        int excludingZero = 1;
        int zeroCount = 0;
        int res[] = new int[size];
        for(int i=0;i<size;i++){
            if(nums[i] == 0) zeroCount++;
            else excludingZero *= nums[i];
        }
        for(int i=0;i<size;i++){
            if(zeroCount > 1){
                res[i] = 0;
            }else if(zeroCount == 1){
                if(nums[i] == 0){
                    res[i] = excludingZero;
                } else {
                    res[i] = 0;
                }
            } else {
                res[i] = excludingZero / nums[i];
            }
        }
        return res;
    }
}