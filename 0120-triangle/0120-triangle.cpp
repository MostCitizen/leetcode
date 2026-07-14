class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        for(int i=t.size()-2;i>=0;i--){
            for(int j=0;j<t[i].size();j++){
                int a = t[i+1][j];
                int b = t[i+1][j+1];
                t[i][j] = t[i][j] + min(a, b);
            }
        }
        return t[0][0];
    }
};