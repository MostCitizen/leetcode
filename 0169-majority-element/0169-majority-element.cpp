class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        sort(nums.begin(), nums.end());
        int count = 1;
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                count++;
            }else {
                count = 1;
            }
            if(count * 2 >= n) return nums[i];
        }
        return -1;
    }
};