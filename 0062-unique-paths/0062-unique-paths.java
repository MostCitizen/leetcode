class Solution {
    public int uniquePaths(int m, int n) {
        int[][] arrs = new int[m][n];
        Arrays.fill(arrs[0], 1);
        for(int i=1;i<m;i++){
            Arrays.fill(arrs[i], 1);
            for(int j=1;j<n;j++){
                arrs[i][j] = arrs[i-1][j] + arrs[i][j-1];
            }
        }
        return arrs[m-1][n-1];
    }
}