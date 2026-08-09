class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> v(26);
        for(int i=0;i<s.size();i++){
            char c = s[i];
            v[c-'a'].push_back(i);
        }
        v.erase(
            remove_if(v.begin(), v.end(), [](const vector<int>& x) {
                return x.empty();
            }),
            v.end()
        );
        sort(v.begin(), v.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        for(int i=0;i<v.size();i++){
            cout << v[i][0] << " " << v[i][v[i].size()-1] << endl;
        }
        
        vector<int> res;
        int start = 0;
        int end = 0;
        for(int i=0;i<v.size();i++){
            if(v[i].empty()) continue;
            if(start == 0 && end == 0 && i == 0){
                start = v[i][0];
                end = v[i][v[i].size()-1];
            }else{
                if((v[i][0] < end && end < v[i][v[i].size()-1]) ||
                    (start < v[i][0] && v[i][0] < end)){
                    start = min(start, v[i][0]);
                    end = max(end, v[i][v[i].size()-1]);
                }else {
                    res.push_back(end - start + 1);
                    start = v[i][0];
                    end = v[i][v[i].size()-1];
                }
            }
        }
        res.push_back(end - start + 1);
        return res;
    }
};