class Solution {
private:
    int init(int d, int m){
        string s = to_string(d);
        int index = s[0] - '0';
        int num = 0;
        int size = s.size();
        for(int i=0;i<size-1;i++){
            num += index;
            num *= 10;
            index++;
            if (index == 10){
                long long t = pow(10, size);
                if(t >= m) return -1;
                return init(t, m);
            }
        }
        num += index;
        cout << " asd " << num << endl;
        return num;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int num = init(low, high);
        while(num <= high){
            if(num >= low)
                res.push_back(num);
            int temp = num % 10;
            string s = to_string(num);
            int size = s.size();
            if(temp == 9){
                num = init(pow(10, size), high);
                if(num == -1) break;
            }
            else {
                num -= ((s[0] - '0') * pow(10, size-1));
                num *= 10;
                num += (temp + 1);
            }
        }
        return res;
    }
};