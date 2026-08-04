class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> v;
        int mn = INT_MAX;
        int mx = -INT_MAX;
        int arr[101] = {0,};

        for(int num : nums){
            arr[num] = 1;
            mn = min(mn, num);
            mx = max(mx, num);
        }
        for(int i=mn;i<mx;i++){
            if(!arr[i]) v.push_back(i);
        }
        return v;
    }
};