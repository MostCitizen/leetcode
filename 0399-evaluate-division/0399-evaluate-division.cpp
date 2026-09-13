class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> map;
        int n = equations.size();
        for(int i=0;i<n;i++){
            string a = equations[i][0];
            string b = equations[i][1];
            map[a].push_back({b, values[i]});
            map[b].push_back({a, 1/values[i]});
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            set<string> s;
            res.push_back(cal(map, queries[i][0], queries[i][1], s, 1));
        }
        return res;
    }

    double cal(unordered_map<string, vector<pair<string, double>>> map, string cur, string find, set<string> s, double c){
        if(!map.contains(cur) || !map.contains(find)) return -1;
        else if(cur == find) return 1;
        s.insert(cur);
        for(auto [next, cost] : map[cur]){
            if(s.contains(next)) continue;
            else if(next == find) return c * cost;
            s.insert(next);
            double val = cal(map, next, find, s, c);
            if(val != -1) return val * cost;
        }
        return -1;
    }
};