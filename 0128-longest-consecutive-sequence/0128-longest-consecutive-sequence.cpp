class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int m = 0;
        int length = 1;
        set<int> set(nums.begin(), nums.end());
        for(int num : set){
            if(set.find(num + 1) != set.end()){
                length++;
            }
            else{
                m = max(m, length);
                length = 1;
            }
        }
        m = max(m, length);
        return m;
    }
};