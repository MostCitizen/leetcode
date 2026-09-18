class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int, int>> map;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(map.contains(s[i])) continue;
            for(int j=n-1;j>=i;j--){
                if(s[i] == s[j]){
                    map[s[i]] = {i, j};
                    break;
                }
            }
        }
        vector<pair<int, int>> sub;
        for(auto [c, pair] : map){
            auto [start, end] = pair;
            bool isAble = true;
            for(int i = start+1;i<end;i++){
                if(map[s[i]].first < start) {
                    isAble = false;
                    break;
                }
                end = max(end, map[s[i]].second);
            }
            if(isAble){
                sub.push_back({start, end});
            }
        }
        sort(sub.begin(), sub.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        vector<string> res;
        int currentStart = 0;
        for(auto [start, end] : sub){
            cout << start << " " << end << endl;
            if(currentStart <= start){
                currentStart = start;
                res.push_back(s.substr(start, end-start+1));
            }
        }
        return res;
    }
};