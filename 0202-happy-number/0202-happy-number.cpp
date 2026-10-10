class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n != 1){
            if(s.contains(n)) return false;
            int sum = 0;
            s.insert(n);
            while(n){
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};