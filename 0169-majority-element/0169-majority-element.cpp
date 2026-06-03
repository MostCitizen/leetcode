class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int s = nums.size();
        int c = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<s-1;i++){
            if(nums[i] != nums[i+1]){
                c = max(i+1-c, c);
                if(c < (s/2 + s%2)) continue;
                return nums[i];
            }
        }
        return nums[s-1];
    }
};