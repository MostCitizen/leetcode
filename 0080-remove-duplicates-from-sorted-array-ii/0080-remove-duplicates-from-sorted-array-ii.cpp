class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int remove = 0;
        bool duplicate = false;
        int index = 0;
        for(int i=1;i<n;i++){
            if(nums[index] != nums[i]){
                duplicate = false;
                index++;
            }else if(!duplicate) {
                duplicate = true;
                index++;
            }else {
                remove++;
            }
            nums[index] = nums[i];
        }
        return n - remove;
    }
};