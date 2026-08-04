class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> v;
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        for(int i=mn;i<mx;i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()) v.push_back(i);
        }
        return v;
    }
};