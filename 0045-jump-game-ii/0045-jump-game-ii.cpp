class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int jump = nums[0];
        int count = 1;
        int index = 1;
        while(jump < n-1){
            count++;
            int start = index;
            int end = jump;
            for(int i=start;i<=end;i++){
                if(i >= n) return count;
                if(jump < nums[i] + i){
                    jump = nums[i] + i;
                    index = i;
                }
            }
        }
        return count;
    }
};