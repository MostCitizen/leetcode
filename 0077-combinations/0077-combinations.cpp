class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        bTrack(n, k, 1, comb, result);
        return result;
    }

    void bTrack(int n, int k, int start, vector<int> &comb, vector<vector<int>> &result){
        if(comb.size() == k){
            result.push_back(comb);
            return;
        }
        for(int i=start;i<=n;i++){
            comb.push_back(i);
            bTrack(n, k, i+1, comb, result);
            comb.pop_back();
        }
    }
};