class Solution {
public:
    string addBinary(string a, string b) {
        bool isCarry = false;
        int n = a.size()-1;
        int m = b.size()-1;
        string result = "";
        while(n >= 0 || m >= 0){
            char num1 = n < 0 ? '0' : a[n--];
            char num2 = m < 0 ? '0' : b[m--];
            if(num1 == '1' && num2 == '1'){
                result = (isCarry ? "1" : "0") + result;
                isCarry = true;
            }
            else if(num1 == '1' || num2 == '1'){
                result = (isCarry ? "0" : "1") + result;
            }
            else {
                result = (isCarry ? "1" : "0") + result;
                isCarry = false;
            }
        }
        if(isCarry) result = "1" + result;
        return result;
    }
};