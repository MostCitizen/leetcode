class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({INT_MAX, 0});
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> prev = intervals[0];
        vector<vector<int>> res;
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= prev[1]){
                prev[1] = max(prev[1], intervals[i][1]);
            }else {
                res.push_back(prev);
                prev = intervals[i];
            }
        }
        return res;
    }
};