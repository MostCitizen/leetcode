class Solution {
public:
    int minOperations(string s) {
        int res = 0;
        int n = s.size();
        if(n == 1) return 0;
        else if(n == 2) {
            return s[0] > s[1] ? -1 : 0;
        }
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        if(sorted == s) return 0;

        int minIndex = 0;
        int maxIndex = 0;
        for(int i=1;i<n;i++){
            if(s[minIndex] > s[i]) minIndex = i;
            if(s[maxIndex] <= s[i]) maxIndex = i;
        }
        if(minIndex == 0 && maxIndex == n-1) return 1;
        else if(minIndex == 0 || maxIndex == n-1) return 1;
        else if(minIndex == n-1 && maxIndex == 0) {
            sort(s.begin(), s.end()-1);
            sort(s.begin()+1, s.end());
            return s == sorted ? 2 : 3;
        }
        else if(minIndex == n-1 || maxIndex == 0) return 2;
        else return 2;
    }
};