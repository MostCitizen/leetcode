class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int max = 0;
        int best = 0;
        for(int i=0;i<prices.length;i++){
            max = Math.max(max, prices[i]);
            best = Math.max(best, max - min);
            if(min > prices[i]){
                min = prices[i];
                max = prices[i];
            }
        }
        return best;
    }
}