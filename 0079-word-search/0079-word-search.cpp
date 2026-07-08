class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(find(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, string word, int k, int row, int col){
        if(word.size() == k){
            return true;
        }
        if(row >= board.size() || row<0 || 
           col >= board[0].size() || col < 0 || 
           board[row][col] != word[k]){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '\0';
        bool res = find(board, word, k + 1, row+1, col) || 
               find(board, word, k + 1, row, col+1) || 
               find(board, word, k + 1, row-1, col) || 
               find(board, word, k + 1, row, col-1);
        board[row][col] = temp;
        return res;
    }
};