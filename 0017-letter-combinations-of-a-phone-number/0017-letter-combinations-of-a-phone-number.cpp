class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        queue<string> q;
        string phone[] = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        for(char c : digits){
            int digit = c - '0';
            int size = q.size();
            if(!size){
                for(char letter : phone[digit]){
                    string str(1, letter);
                    q.push(str);
                }
            }else {
                for(int i=0;i<size;i++){
                    string cur = q.front();
                    q.pop();
                    for(int j=0;j<phone[digit].size();j++){
                        q.push(cur + phone[digit][j]);
                    }
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};