class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(res, n, 0, "", 0, 0);
        return res;
    }
    private void backtrack(List<String> res, int n, int count, String s, int openCount, int closeCount){
        if(openCount < 0 || openCount > n || openCount < closeCount) return;
        if(count/2 == n){
            res.add(s);
            return;
        }
        count++;
        backtrack(res, n, count, s + "(", openCount+1, closeCount);
        backtrack(res, n, count, s + ")", openCount, closeCount+1);
    }
}