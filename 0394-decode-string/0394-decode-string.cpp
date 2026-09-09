class Solution {
public:
    string decodeString(string s) {
        stack<string> strs; 
        stack<int> nums; 
        int num = 0;
        string res = "";
        for(char c : s){
            if(c == '['){
                nums.push(num);
                strs.push(res);
                num = 0;
                res = "";
            }else if(isdigit(c)){
                num *= 10;
                num += c - '0';
            }else if(c == ']'){
                int count = nums.top();
                nums.pop();
                string prev = strs.top();
                strs.pop();
                string temp = "";
                for(int i=0;i<count;i++){
                    temp += res;
                }
                res = prev + temp;
            }else {
                res += c;
            }
        }
        return res;
    }
};