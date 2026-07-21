class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        string temp;
        for(char c : searchWord){
            temp += c;
            vector<string> v;
            for(int i=0;i<products.size() && v.size() < 3;i++){
                if(products[i].substr(0, temp.size()) == temp){
                    v.push_back(products[i]);
                }
            }

            res.push_back(v);
        }
        return res;
    }
};