class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m == 1 && n == 1) return (double)(nums1[0] + nums2[0]) / 2;
        
        vector<int> temp;
        for(int i=0;i<m;i++){
            temp.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            temp.push_back(nums2[i]);
        }
        sort(temp.begin(),temp.end());
        int mid = (m+n)/2;
        if((m+n)%2 == 1){
            return (double)temp[mid];
        }
        else {
            return (double)(temp[mid]+temp[mid-1])/2;
        }
    }
};