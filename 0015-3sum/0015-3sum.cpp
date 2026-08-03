class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = size-1;
            while(left < right){
                int total = nums[i] + nums[left] + nums[right];
                if(total == 0){
                    v.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(nums[left] == nums[left-1] && left < right){
                        left++;
                    }
                }else if(total < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return v;
    }
};