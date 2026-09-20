class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (right + left) / 2;
            int midVal = nums[mid];
            if((mid - 1 < 0 ? midVal >= INT_MIN : midVal > nums[mid-1]) && 
                (mid+1 >= n ? midVal >= INT_MIN : midVal > nums[mid+1])){
                return mid;
            }else if(mid - 1 < 0) left = mid + 1;
            else if(mid + 1 >= n) right = mid - 1;
            else if(nums[mid-1] < nums[mid+1]){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }
};