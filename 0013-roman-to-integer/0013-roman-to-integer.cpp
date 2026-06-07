class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c == 'I'){
                int num = 1;
                if(s[i+1] == 'V'){
                    num = 4;
                    i++;
                }
                else if(s[i+1] == 'X'){
                    num = 9;
                    i++;
                }
                result += num;
            }
            else if(c == 'V'){
                result += 5;
            }
            else if(c == 'X'){
                int num = 10;
                if(s[i+1] == 'L'){
                    num = 40;
                    i++;
                }
                else if(s[i+1] == 'C'){
                    num = 90;
                    i++;
                }
                result += num;
            }
            else if(c == 'L'){
                result += 50;
            }
            else if(c == 'C'){
                int num = 100;
                if(s[i+1] == 'D'){
                    num = 400;
                    i++;
                }
                else if(s[i+1] == 'M'){
                    num = 900;
                    i++;
                }
                result += num;
            }
            else if(c == 'D'){
                result += 500;
            }
            else if(c == 'M'){
                result += 1000;
            }
        }
        return result;
    }
};