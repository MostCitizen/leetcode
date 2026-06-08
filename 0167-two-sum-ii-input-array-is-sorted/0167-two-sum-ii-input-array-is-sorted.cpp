class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0, right = numbers.size()-1;
        sort(numbers.begin(), numbers.end());
        while(left < right){
            int temp = numbers[left] + numbers[right];
            if(temp == target) break;
            else if(temp < target) left++;
            else right--;
        }
        return {left+1, right+1};
    }
};