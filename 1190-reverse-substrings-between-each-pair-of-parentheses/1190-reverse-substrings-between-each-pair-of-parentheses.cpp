class Solution {
public:
    string reverseParentheses(string s) {
        string cur;
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(cur);
                cur = "";
            }else if(s[i] == ')'){
                reverse(cur.begin(), cur.end());
                cur = st.top() + cur;
                st.pop();
            }else {
                cur += s[i];
            }
        }
        return cur;
    }
};