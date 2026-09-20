class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1, right = *max_element(piles.begin(), piles.end());
        if(n == h){
            return right;
        }
        int cur = 0;
        int k = 1;
        int res = INT_MAX;
        while(left <= right){
            int mid = (right + left) / 2;
            if(allEat(piles, h, mid)){
                res = min(res, mid);
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return res;
    }

    bool allEat(vector<int>& piles, int h, int k){
        int cur = 0;
        for(int i=0;i<piles.size();i++){
            int ba = piles[i];
            cur += (ba / k + (ba % k != 0 ? 1 : 0));
            if(cur > h) {
                return false;
            }
        }
        return true;
    }
};