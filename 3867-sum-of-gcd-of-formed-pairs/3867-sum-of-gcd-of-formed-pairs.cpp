class Solution {
public:
    int gcd(int a, int b){
        int temp;
        while(b){
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            mx = max(mx, nums[i]);
            v.push_back(gcd(mx, nums[i]));
        }
        long long res = 0;
        int size = v.size();
        sort(v.begin(), v.end());
        for(int i=0;i<size/2;i++){
            res += gcd(v[size-1-i], v[i]);
        }
        return res;
    }
};