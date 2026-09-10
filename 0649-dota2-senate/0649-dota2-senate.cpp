class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rQ, dQ;
        queue<char> q(senate.begin(), senate.end());

        while(!q.empty()){
            char c = q.front();
            q.pop();
            if(c == 'R') {
                if(dQ.empty()){
                    rQ.push(1);
                }else{
                    q.push('D');
                    dQ.pop();
                }
            }else{
                if(rQ.empty())
                    dQ.push(1);
                else {
                    q.push('R');
                    rQ.pop();
                }
            }
        }
        return rQ.size() >= dQ.size() ? "Radiant" : "Dire";
    }
};