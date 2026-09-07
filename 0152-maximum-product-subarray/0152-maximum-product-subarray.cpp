class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int x = nums[i];
            int newMax = max({x, maxProduct*x, minProduct*x});
            int newMin = min({x, maxProduct*x, minProduct*x});
            maxProduct = newMax;
            minProduct = newMin;
            res = max(res, maxProduct);
        }
        return res;
    }
};