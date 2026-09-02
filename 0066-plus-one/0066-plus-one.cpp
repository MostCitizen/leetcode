class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] != 9) {
            digits[n-1]+=1;
            return digits;
        }
        int carry = 1;
        digits[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            if(digits[i] + 1 > 9){
                carry = 1;
                digits[i] = 0;
            }else{
                carry = 0;
                digits[i]++;
                break;
            }
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};