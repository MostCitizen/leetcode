class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int m = 1;
        int length = 1;
        bool isUp = false;
        for(int i=0;i<n-1;i++){
            if(nums[i] - nums[i+1] >= 1){
                if(isUp){
                    isUp = false;
                    length = 1;
                }
                length++;
                m = max(m, length);
            }else if(nums[i+1] - nums[i] >= 1){
                if(!isUp){
                    isUp = true;
                    length = 1;
                }
                length++;
                m = max(m, length);
            }else {
                length = 1;
            }
        }
        return m;
    }
};