class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        int l = 0, r = nums.size()-1;
        sort(nums.begin(), nums.end());
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum == target) break;
            else if(sum < target) l++;
            else r--;
        }
        if(nums[l] == nums[r]){
            return {map[nums[l]][0], map[nums[r]][1]};
        }
        return {map[nums[l]][0], map[nums[r]][0]};
    }
};