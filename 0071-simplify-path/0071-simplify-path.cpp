class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        for(int i=0;i<n;i++){
            if(path[i] == '/') continue;
            string temp = "";
            while(i < n && path[i] != '/'){
                temp += path[i++];
            }
            if(temp == ".."){
                if(!st.empty())
                    st.pop();
            }else if(temp == ".") {
                continue;
            }else {
                st.push(temp);
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + "/" + res;
            st.pop();
        }
        if(res != "") {
            res.pop_back();
            return "/" + res;
        }else {
            return "/";
        }
    }
};