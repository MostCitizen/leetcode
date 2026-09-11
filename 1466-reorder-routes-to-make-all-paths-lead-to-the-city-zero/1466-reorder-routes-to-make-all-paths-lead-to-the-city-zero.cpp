class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i=0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];

            graph[a].push_back({b, 1});
            graph[b].push_back({a, 0});
        }
        return find(graph, 0, -1);
    }

    int find(vector<vector<pair<int, int>>>& graph, int cur, int parent){
        int res = 0;
        for(auto [next, cost] : graph[cur]){
            if(next == parent) continue;
            res += cost;
            res += find(graph, next, cur);
        }
        return res;
    }
};