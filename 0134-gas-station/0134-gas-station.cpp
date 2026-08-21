class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0;
        int size = gas.size();
        int gasTotal = 0;
        while(index < size){
            int i;
            for(i=0;i<size;i++){
                int temp = (i+index)%size;
                if(gas[temp] == 0 && gasTotal == 0) {
                    index++;
                    break;
                }
                gasTotal += gas[temp] - cost[temp];
                if(gasTotal < 0){
                    gasTotal = 0;
                    index++;
                    break;
                }
            }
            if(i == size) return index;
            else index = (i+index);
        }
        return -1;
    }
};