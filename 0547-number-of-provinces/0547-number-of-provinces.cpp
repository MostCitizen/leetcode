class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, int> mp;
        vector<bool> v(n);
        queue<int> q;
        int index = 0;
        for(int i=0;i<n;i++){
            if(v[i]) continue;
            v[i] = true;
            mp[index] = 1;
            for(int j=i+1;j<n;j++){
                if(!isConnected[i][j]) continue;
                q.push(j);
            }
            while(!q.empty()){
                int val = q.front();
                q.pop();
                if(v[val]) continue;
                mp[index] = 1;
                v[val] = true;
                if(val == i) continue;
                for(int j=0;j<n;j++){
                    if(val == j || j == i || !isConnected[val][j]) continue;
                    q.push(j);
                }   
            }
            index++;
        }
        return mp.size();
    }
};