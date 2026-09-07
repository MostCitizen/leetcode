class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        v.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> temp(i+1);
            temp[0] = 1;
            temp[i] = 1;
            v.push_back(temp);
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                v[i][j] = v[i-1][j-1] + v[i-1][j];
            }
        }
        return v;
    }
};