class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 2;
        int prod = 1;
        int left = 0;
        for(int right = 0;right<nums.size();right++){
            int num = nums[right];
            while(gcd(prod, num) > 1){
                prod /= nums[left++];
            }
            prod *= num;
            res = max(res, right - left + 1);
        }
        return res;
    }
};