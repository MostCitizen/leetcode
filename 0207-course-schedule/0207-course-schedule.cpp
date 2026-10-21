class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        vector<int> visits(numCourses);
        for(vector<int> v : prerequisites){
            map[v[0]].push_back(v[1]);
        }
        for(auto [key, val] : map){
            if(isLoop(map, visits, key)) return false;
        }
        return true;
    }
    bool isLoop(unordered_map<int, vector<int>>& map, vector<int>& visits, int val){
        if(visits[val] == 1) return true;
        else if(visits[val] == 2) return false;
        visits[val] = 1;
        for(int num : map[val]){
            if(isLoop(map, visits, num)) return true;
        }
        visits[val] = 2;
        return false;
    }
};