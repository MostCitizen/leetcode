class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        vector<int> v;
        int result = 1;
        sort(nums.begin(), nums.end());
        for(int num : nums){
            mp[num]++;
        }
        long long target = 0;
        int index = 1;
        for(int i=0;i<nums.size();i++){
            target = nums[i];
            if(target == 1) {
                result = max(result, mp[nums[i]] % 2 == 1 ? mp[nums[i]] : mp[nums[i]]-1); 
                continue;
            }
            auto it = mp.find(target * target);
            if(mp[nums[i]] >= 2){
                mp[nums[i]] = 0;
                while(it != mp.end()){
                    target = it->first;
                    cout << target << endl;
                    index += 2;
                    if(it->second < 2){
                        break;
                    }
                    it->second = 0;
                    it = mp.find(target * target);
                }
                result = max(result, index);
                index = 1;
            }
        }
        return max(result, index);
    }
};