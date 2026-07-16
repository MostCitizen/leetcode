class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> v(rooms.size());
        v[0] = true;
        int size = rooms.size();
        queue<int> q;
        for(int i=0;i<rooms[0].size();i++){
            q.push(rooms[0][i]);
        }
        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(v[val]) continue;
            v[val] = true;
            for(int i=0;i<rooms[val].size();i++){
                q.push(rooms[val][i]);
            }
        }
        for(int i=0;i<v.size();i++){
            if(!v[i]) return false;
        }
        return true;
    }
};