class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int left = 0, right = n -1;
        while(left <= right){
            int leftV = nums[left];
            int rightV = nums[right];
            if(leftV > rightV){
                right--;
            }
            else if(right == n-1){
                return nums[left];
            }
            else {
                return nums[right+1];
            }
        }
        return -1;
    }
};