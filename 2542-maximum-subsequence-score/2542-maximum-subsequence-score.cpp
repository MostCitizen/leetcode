class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        int size = nums1.size();
        for(int i=0;i<size;i++){
            v.push_back(make_pair(nums2[i], nums1[i]));
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long res = 0;

        for(int i=0;i<size;i++){
            int m = v[i].first;
            int val = v[i].second;
            pq.push(val);
            sum += val;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                res = max(res, sum * m);
            }
        }
        return res;
    }
};