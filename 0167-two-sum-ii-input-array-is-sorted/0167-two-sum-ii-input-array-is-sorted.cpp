class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        for(int i=0;i<numbers.size();i++){
            map[numbers[i]] = i + 1;
        }
        vector<int> v;

        for(int i=0;i<numbers.size();i++){
            if(map.contains(target - numbers[i])){
                return {i + 1, map[target - numbers[i]]};
            }
        }
        return {-1, -1};
    }
};