class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 1;
        else if(size == 2) return 2;
        int n = size;
        int r = 0;
        while(n){
            r++;
            n = n / 2;
        }
        return pow(2, r);
    }
};