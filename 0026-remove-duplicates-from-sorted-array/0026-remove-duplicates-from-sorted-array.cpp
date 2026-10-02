class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        int remove = 0;
        for(int i=1;i<n;i++){
            if(nums[index] != nums[i]){
                nums[++index] = nums[i];
            }else {
                remove++;
            }
        }
        return n - remove;
    }
};