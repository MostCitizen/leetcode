class Solution {
public:
    int maxVowels(string s, int k) {
        int m = 0;
        int vowels = 0;
        queue<char> q;

        for(char c : s){
            q.push(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vowels++;
            }
            if(!q.empty() && q.size() > k){
                char temp = q.front();
                q.pop();
                if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){
                    vowels--;
                }   
            }
            if(q.size() == k){
                m = max(m,vowels);
            }
        }
        return m;
    }
};