class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        back(res, n, 0, 0, "");
        return res;
    }

    void back(vector<string>& res, int n, int openC, int closeC, string s){
        if(openC < closeC || openC > n || closeC > n) return;
        else if(closeC == n) {
            res.push_back(s);
            return;
        }
        back(res, n, openC+1, closeC, s + "(");
        back(res, n, openC, closeC+1, s + ")");
    }
};