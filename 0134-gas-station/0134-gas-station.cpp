class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        int res = 0;
        cout << start << endl;
        for(int i=0;i<n;i++){
            int index = (start + i) % n;
            res += gas[i] - cost[i];
        }
        return res >= 0 ? start % n : - 1;
    }
};