class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        int total = 1;
        int n = nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(nums[i] == 0) {
                zero++;
                continue;
            }
            total *= nums[i];
        }
        if(zero > 1) return res;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                res[i] = total;
            }else {
                res[i] = zero == 1 ? 0 : total / nums[i];
            }
        }
        return res;
    }
};