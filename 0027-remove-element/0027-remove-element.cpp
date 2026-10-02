class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = n-1;
        int remove = 0;
        while(left <= right){
            if(nums[left] == val){
                remove++;
                while(right > left && nums[right] == val){
                    right--;
                    remove++;
                }
                nums[left] = nums[right];
                right--;
            }
            left++;
        }
        return n - remove;
    }
};