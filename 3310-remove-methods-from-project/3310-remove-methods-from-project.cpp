class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(vector<int> invocation : invocations){
            int a = invocation[0];
            int b = invocation[1];
            graph[a].push_back(b);
        }
        vector<bool> suspicious(n, false);
        queue<int> q;
        suspicious[k] = true;
        q.push(k);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int next : graph[cur]){
                if (suspicious[next]) {
                    continue;
                }
                suspicious[next] = true;
                q.push(next);
            }
        }
        vector<int> res;
        bool isAll = false;
        for(vector<int> invocation : invocations){
            int a = invocation[0];
            int b = invocation[1];
            if(!suspicious[a] && suspicious[b]){
                isAll = true;
            }
        }
        for(int i=0;i<n;i++){
            if(!suspicious[i] || isAll){
                res.push_back(i);
            }
        }
        return res;
    }
};