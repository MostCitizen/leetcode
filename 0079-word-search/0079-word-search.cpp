class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    bool res = find(board, word, i, j, 0);
                    if(res) return res;
                }
            }
        }
        return false;
    }
    bool find(vector<vector<char>>& board, string word, int r, int c, int index){
        if(r < 0 || r >= board.size() || 
            c < 0 || c >= board[0].size()) return false;
        else if(board[r][c] != word[index]) return false;
        else if(index == word.size()-1) return true;
        board[r][c] = '\0';
        bool res = find(board, word, r+1, c, index+1) || 
                find(board, word, r-1, c, index+1) ||
                find(board, word, r, c+1, index+1) ||
                find(board, word, r, c-1, index+1);
        board[r][c] = word[index];
        return res;
    }
};