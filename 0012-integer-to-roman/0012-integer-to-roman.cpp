class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        unordered_map<int, string> roman = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        int re = 1000;
        while(re != 0){
            int temp = num/re;
            if(temp == 4 || temp == 9){
                result += roman[temp*re];
            }
            else {
                int refeat = temp;
                if(refeat >=  5){
                    refeat -= 5;
                    result += roman[re * 5];
                }
                for(int i=0;i<refeat;i++) result += roman[re];
            }
            num -= temp * re;
            re /= 10;
        }

        return result;
    }
};