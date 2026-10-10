class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long total = 0;
        long long k = k1 + k2;
        int m = 0;
        vector<int> diff(n, 0);
        for(int i=0;i<n;i++){
            int x = abs(nums1[i] - nums2[i]);
            total += x;
            diff[i] = x;
            m = max(m, x);
        }
        if(total <= k) return 0;
        vector<long long> v(m+1, 0);
        for(int val : diff) v[val]++;
        for(int i=m;m>0 && k>0;i--){
            int take = min(v[i], k);
            v[i] -= take;
            v[i-1] += take;
            m = i;
            k -= take;
        }
        long long res = 0;
        for(int i=0;i<=m;i++){
            res += 1LL * i * i * v[i];
        }
        return res;
    }
};