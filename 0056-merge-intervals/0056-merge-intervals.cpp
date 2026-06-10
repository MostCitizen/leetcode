class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        
        int index = -1;
        int size = intervals.size();
        int f = intervals[0][0], l = intervals[0][1];

        for(int i=1;i<size;i++){
            if(l >= intervals[i][0] && l <= intervals[i][1]){
                l = intervals[i][1];
            }
            else if(l < intervals[i][0]){
                index++;
                result.push_back({f, l});
                f = intervals[i][0];
                l = intervals[i][1];
            }
        }
        if(index == -1 || result.back()[1] < f){
            result.push_back({f, l});
        }
        return result;
    }
};