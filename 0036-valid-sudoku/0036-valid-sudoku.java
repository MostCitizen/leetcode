class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;i++){
            if(!isValidRow(board[i]) || 
                !isValidCol(board, i) || 
                !isValidBox(board, i)) return false;
        }
        return true;
    }

    private boolean isValidRow(char[] row){
        int[] arr = new int[10];
        for(int i=0;i<9;i++){
            if(row[i] == '.') continue;
            else if(arr[row[i]-'0'] > 0) return false;
            arr[row[i]-'0']++;
        }
        return true;
    }

    private boolean isValidCol(char[][] col, int index){
        int[] arr = new int[10];
        for(int i=0;i<9;i++){
            if(col[i][index] == '.') continue;
            else if(arr[col[i][index]-'0'] > 0) return false;
            arr[col[i][index]-'0']++;
        }
        return true;
    }


    private boolean isValidBox(char[][] box, int index){
        int[] arr = new int[10];
        int row = (index / 3) * 3;
        int col = (index % 3) * 3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(box[row+i][col+j] == '.') continue;
                else if(arr[box[row+i][col+j]-'0'] > 0) return false;
                arr[box[row+i][col+j]-'0']++;
            }
        }
        return true;
    }
}