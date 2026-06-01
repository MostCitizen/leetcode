class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        for(int i=0;i<m+n;i++){
            result.push_back(i < m ? nums1[i] : nums2[i-m]);
        }
        nums1 = result;
        sort(nums1.begin(), nums1.end());
        return;
    }
};