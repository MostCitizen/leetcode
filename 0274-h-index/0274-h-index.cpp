class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 1) return 0 < citations[0] ? 1 : 0;
        sort(citations.begin(),citations.end());
        for(int i=0;i<n;i++){
            int h = n - i;
            if(citations[i] >= h){
                return h;
            }
        }
        return 0;
    }
};