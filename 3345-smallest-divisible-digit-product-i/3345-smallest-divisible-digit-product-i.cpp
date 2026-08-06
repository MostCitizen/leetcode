class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n == 100) return n;
        vector<int> v;
        int temp = n;
        while(temp){
            v.push_back(temp%10);
            temp = temp / 10;
        }
        if(v.size() == 1) {
            temp = n % t;
            int res = n + (temp != 0 ? t - temp : 0);
            return min(res, 10);
        }else {
            for(int i=v[0];i<=9;i++){
                if(v[1] * i % t == 0) return v[1] * 10 + i;
            }
            return (v[1] + 1) * 10;
        }
    }
};