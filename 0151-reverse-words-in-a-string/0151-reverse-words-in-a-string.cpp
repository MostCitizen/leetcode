class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n == 1) return s;
        reverse(s.begin(), s.end());
        s += " ";
        n++;
        int index = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            s[index] = s[i];
            if(s[i] != ' ') {
                index++;
            }
            else if(index > 0 && s[index-1] != ' '){
                reverse(s.begin() + start, s.begin() + index);
                cout << start << "  "<<index << endl;
                s[index++] = ' ';
                start = index;
            }
            
        }
        while(s[index-1] == ' '){
            index--;
        }
        s = s.substr(0, index);
        return s;
    }
};