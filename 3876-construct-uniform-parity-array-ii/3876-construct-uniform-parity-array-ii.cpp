class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int m = INT_MAX;
        int oddCount = 0;
        for(int num : nums1){
            m = min(m, num);
            if(num % 2 == 1) oddCount++;
        }
        return oddCount == 0 || m % 2 == 1;
    }
};