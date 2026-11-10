class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        digits[n-1] += 1;
        for(int i=n-1;i>=0;i--){
            int num = digits[i];
            digits[i] = (carry + digits[i]) % 10;
            carry = (carry + num) / 10;
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};