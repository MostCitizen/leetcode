class Solution {
public:
    bool sumGame(string num) {
        int size = num.size();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;
        for(int i=0;i<size;i++){
            if(i < size/2){
                if(num[i] == '?') leftQ++;
                else leftSum += num[i]-'0';
            }else{
                if(num[i] == '?') rightQ++;
                else rightSum += num[i]-'0';
            }
        }
        if((rightQ +leftQ) % 2 == 1) return true;
        int sumDiff = rightSum - leftSum;
        int qDiff = rightQ - leftQ;

        return sumDiff != (qDiff/2) * -9;
    }
};