class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!isValidRow(board[i]) || !isValidCol(board, i) || !isValidBox(board, i)) return false;
        }
        return true;
    }

    bool isValidRow(vector<char> board){
        int arr[10] = {0,};
        for(int i=0;i<9;i++){
            if(board[i] == '.') continue;
            arr[board[i]-'0']++;
            if(arr[board[i]-'0'] > 1) return false;
        }
        return true;
    }

    bool isValidCol(vector<vector<char>> board, int col){
        int arr[10] = {0,};
        for(int i=0;i<9;i++){
            if(board[i][col] == '.') continue;
            arr[board[i][col]-'0']++;
            if(arr[board[i][col]-'0'] > 1) return false;
        }
        return true;
    }

    bool isValidBox(vector<vector<char>> board, int num){
        int row = (num / 3) * 3;
        int col = (num % 3) * 3;
        int arr[10] = {0,};
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j] == '.') continue;
                arr[board[i][j]-'0']++;
                if(arr[board[i][j]-'0'] > 1) return false;
            }
        }
        return true;
    }
};