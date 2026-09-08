class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        vector<vector<int>> v(numCourses);
        vector<int> visits(numCourses);

        for(vector<int> prerequisite : prerequisites){
            v[prerequisite[0]].push_back(prerequisite[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!DFS(v, i, visits)) return false;
        }
        return true;
    }
    bool DFS(vector<vector<int>>& graph, int target, vector<int>& visits){
        if(visits[target] == 1) return false;
        else if(visits[target] == 2) return true;
        visits[target] = 1;
        for(int num : graph[target]){
            if(!DFS(graph, num, visits)) return false;
        }
        visits[target] = 2;
        return true;
    }
};