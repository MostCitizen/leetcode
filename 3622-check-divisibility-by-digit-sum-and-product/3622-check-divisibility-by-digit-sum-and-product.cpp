class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        vector<int> v;
        for(char c : to_string(n)){
            int num = c-'0';
            sum += num;
            product *= num;
        }
        return n % (sum + product) == 0;
    }
};