class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        unordered_map<int, int> map;
        for(int i=0;i<word.size();i++){
            map[word[i] - 'a']++;
        }
        vector<pair<int, int>> v(map.begin(), map.end());
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        for(int i=0;i<v.size();i++){
            count += ((i / 8) + 1) * v[i].second;
        }
        return count;
    }
};