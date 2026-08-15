class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int size = nums.size();
        int bit = 0;
        for(int i=0;i<size;i++){
            bit ^= nums[i];
        }
        if(bit != 0) return size;
        for(int i=0;i<size;i++){
            if(bit ^ nums[i] != 0) return size-1;
        }
        return 0;
    }
};