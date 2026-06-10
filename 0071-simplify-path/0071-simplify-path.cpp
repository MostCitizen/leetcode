class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        for(char c : path){
            if(c == '/' && temp != ""){
                if(temp == ".."){
                    if(!st.empty())
                        st.pop();
                }
                else if(temp != "."){
                    st.push(temp);
                }
                temp = "";
            }
            else if(c != '/') temp += c;
        }
        if(temp == ".."){
            if(!st.empty())
                st.pop();
        }
        else if(temp != "" && temp != "."){
            st.push(temp);
        }
        string result = "";
        while(!st.empty()){
            string s = st.top();
            st.pop();
            result = ("/" + s) + result;
        }
        if(result == "") result = "/";
        return result;
    }
};