class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int f = intervals[0][0], l = intervals[0][1];
        int size = intervals.size();
        int index = -1;
        vector<vector<int>> result;
        for(int i=1;i<size;i++){
            if(l >= intervals[i][0] && l <= intervals[i][1]){
                l = intervals[i][1];
            }
            else if(l <= intervals[i][0]){
                index++;
                result.push_back({f, l});
                f = intervals[i][0];
                l = intervals[i][1];
            }
        }

        if(index == -1 || result.back()[1] < intervals[size-1][0]){
            result.push_back({f, l});
        }
        return result;
    }
};