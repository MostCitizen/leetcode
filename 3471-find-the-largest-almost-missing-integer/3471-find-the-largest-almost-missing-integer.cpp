class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int arr[51] = {0, };
        set<int> s;
        int size = nums.size();
        int subCount = size - k + 1;
        for(int i=0;i<subCount;i++){
            for(int j=0;j<k;j++){
                s.insert(nums[i+j]);
            }
            for(int el : s){
                arr[el]++;
            }
            s.clear();
        }
        int res = -1;
        for(int i=0;i<=50;i++){
            cout << i << " " << arr[i] << endl;
            if(arr[i] == 1) res = i;
        }
        return res;
    }
};