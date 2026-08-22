class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(int i=0;i<strs.size();i++){
            string order = strs[i];
            sort(order.begin(), order.end());
            map[order].push_back(strs[i]);
        }
        vector<vector<string>> res;
        int index = 0;
        for(auto el : map){
            res.push_back(el.second);
        }
        return res;
    }
};