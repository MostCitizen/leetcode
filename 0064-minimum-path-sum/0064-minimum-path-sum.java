class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] arrs = new int[m][n];
        arrs[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            arrs[i][0] = grid[i][0] + arrs[i-1][0];
        }
        for(int i=1;i<n;i++){
            arrs[0][i] = grid[0][i] + arrs[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                arrs[i][j] = grid[i][j] + Math.min(arrs[i][j-1], arrs[i-1][j]);
            }
        }
        return arrs[m-1][n-1];
    }
}