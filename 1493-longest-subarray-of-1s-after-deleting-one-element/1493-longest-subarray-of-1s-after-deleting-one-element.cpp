class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = 0;
        int s = 0;
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0)
                zeroCount++;
            while(zeroCount > 1){
                if(nums[s] == 0)
                    zeroCount--;
                s++;
            }
            m = max(m, i - s);
        }
        return m;
    }
};