class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                temp.push_back(i);
            }
        }
        for(int i=0;i<temp.size();i++){
            nums.erase(nums.begin() + temp[i] - i);
        }
        return nums.size();
    }
};