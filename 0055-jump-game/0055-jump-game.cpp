class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jump = nums[0];
        for(int i=1;i<n;i++){
            if(jump < i) return false;
            jump = max(jump, nums[i] + i);
        }
        return true;
    }
};