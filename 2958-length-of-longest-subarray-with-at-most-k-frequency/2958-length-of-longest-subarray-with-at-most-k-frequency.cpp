class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int start = 0;
        int count = 0;
        int m = 0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]] == k) {
                m = max(m, count);
                while(mp[nums[i]] >= k){
                    mp[nums[start++]]--;
                    count--;
                }
            }
            mp[nums[i]]++;
            count++;
        }
        m = max(m, count);
        return m;
    }
};