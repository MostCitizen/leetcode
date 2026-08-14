class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        vector<int> res(k);
        for(int i=0;i<k;i++){
            res[i] = v[i].first;
        }
        return res;
    }
};