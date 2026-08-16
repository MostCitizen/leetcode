class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        List<Integer> row = new ArrayList<>();
        List<Integer> col = new ArrayList<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] != 0) continue;
                if(!row.contains(i)) row.add(i);
                if(!col.contains(j)) col.add(j);
            }
        }
        for(int i=0;i<row.size();i++){
            int r = row.get(i);
            for(int j=0;j<n;j++){
                matrix[r][j] = 0;
            }
        }
        for(int i=0;i<col.size();i++){
            int c = col.get(i);
            for(int j=0;j<m;j++){
                matrix[j][c] = 0;
            }
        }
    }
}