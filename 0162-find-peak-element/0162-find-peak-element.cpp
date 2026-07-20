class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        int l = 0, r = size-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(mid == 0){
                if(nums[mid] > nums[mid+1])
                    return mid;
                l = mid+1;
            }
            else if(mid == size-1){
                if(nums[mid-1] < nums[mid])
                    return mid;
                r = mid-1;
            }
            else{
                if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                    return mid;
                }
                else if(nums[mid] < nums[mid+1]){
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
        }
        return l;
    }
};