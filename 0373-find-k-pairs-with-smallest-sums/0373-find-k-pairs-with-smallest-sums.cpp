class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        int m = nums1.size();
        int n = nums2.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else {
                    break;
                }
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};