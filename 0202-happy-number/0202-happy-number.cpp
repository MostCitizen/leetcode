class Solution {
public:
    bool isHappy(int n) {
        set<int> s;

        while(n != 1){
            if(s.contains(n)) break;
            s.insert(n);
            n = cal(n);
        }
        return n == 1;
    }

    int cal(int n){
        int sum = 0;
        while(n){
            sum += pow(n%10, 2);
            n = n/10;
        }
        return sum;
    }
};