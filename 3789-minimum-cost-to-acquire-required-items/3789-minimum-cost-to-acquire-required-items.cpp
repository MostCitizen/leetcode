class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost = cost1 + cost2;
        if(cost < costBoth){
            return (long long)cost1 * need1 + (long long)cost2 * need2;
        }else{
            long long res = 0;
            if(need1 < need2){
                res += ((long long)costBoth * need1);
                res += ((long long)(cost2 < costBoth ? cost2 : costBoth) * (need2 - need1));
            }else {
                res += ((long long)costBoth * need2);
                res += ((long long)(cost1 < costBoth ? cost1 : costBoth) * (need1 - need2));
            }
            return res;
        }
    }
};