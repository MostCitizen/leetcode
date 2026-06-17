class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        vector<int> result(n+1);
        int carry = 0;
        digits[n]+=1;

        for(int i=digits.size()-1;i>=0;i--){
            int num = digits[i] + carry;
            carry = num / 10;
            result[i] = (num%10);
        }
        if(carry) result.insert(result.begin(), carry);
        return result;
    }
};