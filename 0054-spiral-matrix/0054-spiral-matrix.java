class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int m = matrix.length;
        int n = matrix[0].length;
        int x = 0, y = 0;
        int dx = 1, dy = 0;
        for(int i=0;i<m*n;i++){
            list.add(matrix[y][x]);
            matrix[y][x] = 101;
            if(!(0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < m) || matrix[y+dy][x+dx] == 101){
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            x += dx;
            y += dy;
        }
        return list;
    }
}