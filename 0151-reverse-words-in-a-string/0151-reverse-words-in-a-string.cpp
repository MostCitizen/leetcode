class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        int n = s.size();
        int i = 0;
        while(i<n){
            while(i<n && s[i] == ' '){
                i++;
            }
            if(i>=n) break;
            if(index > 0){
                s[index++] = ' ';
            }

            while(index < n && i < n && s[i] != ' '){
                s[index++] = s[i++];
            }
        }
        n = index;
        s.resize(n);
        reverse(s.begin(),s.end());
        int start = 0;
        for(int j=0;j<n;j++){
            if(s[j] == ' '){
                reverse(s.begin() + start, s.begin() + j);
                start = j + 1;
            }
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};