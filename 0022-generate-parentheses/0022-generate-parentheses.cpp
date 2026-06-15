class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};
        vector<string> result;
        string paren = "";
        temp(result, paren, 0, 0, n);
        return result;
    }

    void temp(vector<string>&result, string paren, int open, int close, int n){
        if(open == close && open + close  == n * 2){
            result.push_back(paren);
            return;
        }
        if(open < n){
            temp(result, paren + "(", open+1, close, n);
        }
        if(close < open){
            temp(result, paren + ")", open, close+1, n);
        }
    }
};