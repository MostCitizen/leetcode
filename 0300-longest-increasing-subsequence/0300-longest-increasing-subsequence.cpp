class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int num : nums){
            if(res.empty() || res.back() < num){
                res.push_back(num);
            }
            else {
                int index = find(res, num);
                res[index] = num;
            }
        }
        return res.size();
    }
    int find(vector<int> v, int target){
        int l = 0;
        int r = v.size()-1;
        while(l <= r){
            int mid = (r+l) / 2;
            if(v[mid] == target){
                return mid;
            }
            else if(v[mid] > target){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};