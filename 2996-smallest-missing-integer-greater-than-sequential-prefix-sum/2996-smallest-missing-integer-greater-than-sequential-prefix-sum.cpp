class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0] + 1;
        unordered_map<int, int> map;
        for(int i=0;i<size;i++){
            map[nums[i]] = i+1;
        }
        int sum = nums[0];
        int index = 1;
        while(index < size && nums[index-1] + 1 == nums[index]){
            sum += nums[index++];;
        }
        while(map[sum] > 0){
            sum++;
        }
        return sum;
    }
};