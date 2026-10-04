class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n == 1) return s;
        int index = 0;
        for(int i=0;i<n;i++){
            if(s[i] != ' ') {
                if(index>0){
                    s[index++] = ' '; 
                }
                while(i < n && s[i] != ' '){
                    s[index++] = s[i++];
                }
            }
        }
        reverse(s.begin(), s.begin() + index);
        int start = 0;
        for(int i=0;i<=index;i++){
            if(i == index || s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        s.resize(index);
        return s;
    }
};