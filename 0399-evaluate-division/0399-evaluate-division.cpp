class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = queries.size();
        vector<double> res(n);
        unordered_map<string, vector<pair<string, double>>> graph;

        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        for(int i=0;i<n;i++){
            set<string> s;
            double c = cal(graph, queries[i][0], queries[i][1], 1, s);
            res[i] = c;
        }
        return res;
    }
    double cal(unordered_map<string, vector<pair<string, double>>> graph, string s, string findS, double c, set<string> se){
        if(!graph.contains(s)) return -1;
        else if(s == findS) return 1;
        vector<pair<string, double>> temp = graph[s];
        se.insert(s);
        for(int i=0;i<temp.size();i++){
            if(se.contains(temp[i].first)) continue;
            se.insert(temp[i].first);
            if(temp[i].first == findS) {
                return c * temp[i].second;
            }else {
                double res = cal(graph, temp[i].first, findS, c * temp[i].second, se);
                if(res != -1) return res;
            }
        }
        return -1;
    }
};