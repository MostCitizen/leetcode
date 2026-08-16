class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        if(sSize < tSize) return "";
        unordered_map<char, int> mp;
        int total = tSize;
        for(char c : t){
            mp[c]++;
        }
        int start = 0;
        int startEnd[2] = {0, INT_MAX};

        for(int i=0;i<sSize;i++){
            if(mp[s[i]]-- > 0) total--;

            if(total == 0){
                while(start < sSize && mp[s[start]] != 0){
                    mp[s[start]]++;
                    start++;
                }
                cout << i << " " << start << endl;
                if(i - start < startEnd[1] - startEnd[0]){
                    startEnd[0] = start;
                    startEnd[1] = i;
                }
                total++;
                mp[s[start]]++;
                start++;
            }
        }
        return startEnd[1] > sSize ? "" : s.substr(startEnd[0], startEnd[1] - startEnd[0] + 1);
    }
};