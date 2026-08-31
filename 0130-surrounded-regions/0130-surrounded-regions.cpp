class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<n;i++){
            DFS(board, 0, i);
            DFS(board, m-1, i);
        }
        for(int i=1;i<m-1;i++){
            DFS(board, i, 0);
            DFS(board, i, n-1);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'Z'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }

    void DFS(vector<vector<char>>& board, int r, int c){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        else if(board[r][c] != 'O') return;
        board[r][c] = 'Z';
        DFS(board, r+1, c);
        DFS(board, r-1, c);
        DFS(board, r, c+1);
        DFS(board, r, c-1);
    }
};