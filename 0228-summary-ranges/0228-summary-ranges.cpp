class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<string> res;
        int start = nums[0];
        int end = nums[0];
        for(int i=1;i<n;i++){
            if(end + 1 == nums[i]){
                end++;
            }else {
                if(start != end)
                    res.push_back(to_string(start) + "->" + to_string(end));
                else 
                    res.push_back(to_string(start));
                start = end = nums[i];
            }
        }
        if(start != end)
            res.push_back(to_string(start) + "->" + to_string(end));
        else 
            res.push_back(to_string(start));
        return res;
    }
};