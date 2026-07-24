class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int max_xor = 2048;

        vector<bool> exists(max_xor);
        vector<bool> v(max_xor);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                exists[nums[i] ^ nums[j]] = true;
            }
        }

        for (int x = 0; x < max_xor; x++) {
            if (!exists[x]) continue;
            for (int num : nums) {
                v[x ^ num] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < max_xor; i++){
            if(v[i]) count++;
        }

        return count;
    }
};