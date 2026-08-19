class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int count = n*2;
        int current = reservedSeats[0][0];
        bool is25 = true, is45 = true, is69 = true;
        for(int i=0;i<reservedSeats.size();i++){
            if(current != reservedSeats[i][0]) {
                current = reservedSeats[i][0];
                if(!is25 && !is45 && !is69) count-=2;
                else if(!is25 || !is69) count--;
                is25 = true;
                is45 = true; 
                is69 = true;
            }
            if(reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 5){
                is25 = false;
            }
            if(reservedSeats[i][1] >= 4 && reservedSeats[i][1] <= 7){
                is45 = false;
            }
            if(reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 9){
                is69 = false;
            }
        }

        if(!is25 && !is45 && !is69) count-=2;
        else if(!is25 || !is69) count--;

        return count;
    }
};