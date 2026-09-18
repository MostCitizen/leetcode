class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums1[i], nums2[i]});
        }
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        long long res = 0;
        long long sum = 0;
        int m = INT_MAX;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            sum += v[i].first;
            m = v[i].second;
            pq.push(v[i].first);
            if(pq.size() == k){
                res = max(res, sum * m);
                sum -= pq.top();
                pq.pop();
            }
        }
        return res;
    }
};