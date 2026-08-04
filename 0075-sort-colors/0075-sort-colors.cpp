class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return;
        int low = 0, mid = 0, high = size-1;
        while(mid <= high){
            if(nums[mid] == 0) swap(nums[mid++], nums[low++]);
            else if(nums[mid] == 1) mid++;
            else swap(nums[mid], nums[high--]);
        }
        return;
    }
};