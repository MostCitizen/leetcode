class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return {};
        int f = nums[0], l = nums[size-1];
        vector<string> result;
        vector<int> temp;
        for(int i=0;i<size-1;i++){
            if(nums[i] + 1 == nums[i+1]){
                temp.push_back(nums[i]);
            }
            else {
                if(temp.size() == 0){
                    result.push_back(to_string(nums[i]));
                }
                else {
                    result.push_back(to_string(temp[0]) + "->" + to_string(nums[i]));
                }
                temp.clear();
            }
        }
        if(temp.size() == 0){
            result.push_back(to_string(nums[size-1]));
        }
        else {
            result.push_back(to_string(temp[0]) + "->" + to_string(nums[size-1]));
        }
        return result;
    }
};