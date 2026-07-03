class Solution {
public:
    bool three(vector<vector<char>> board, int index){
        int row = index / 3 * 3;
        int col = index % 3 * 3;
        unordered_map<int, int> mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row+i][col+j] == '.') continue;
                mp[board[row+i][col+j]]++;
                if(mp[board[row+i][col+j]] > 1) return false;
            }
        }

        return true;
    }
    bool rowCol(vector<vector<char>> board, int row, int col, int target){
        for(int i=col+1;i<9;i++){
            if(board[row][i] == target) return false;
        }
        for(int i=row+1;i<9;i++){
            if(board[i][col] == target) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            bool temp = three(board, i);
            if(!temp) return false;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                bool temp = rowCol(board, i, j, board[i][j]);
                if(!temp) return false;
            }
        }
        return true;
    }

};