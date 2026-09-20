class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int left = 0, right = m-1;
            int count = 0;
            while(left <= right){
                int mid = (right + left) / 2;
                long long cal = (long long)potions[mid] * spells[i];
                if(cal >= success){
                    right = mid - 1;
                }else {
                    left = mid+1;
                }
            }
            count = m - left;
            res.push_back(count);
        }
        return res;
    }
};