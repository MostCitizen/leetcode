class ProductOfNumbers {
public:
    int count = 0;
    int lastZero = -1;
    int mul = 1;
    vector<int> v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) {
            mul = 1;
            lastZero = count;
        }
        else {
            mul *= num;
        }
        v.push_back(mul);
        count++;
    }
    
    int getProduct(int k) {
        int index = count - 1 - k;
        if(lastZero != -1 && index < lastZero) return 0;
        else if(count == 1) return v[0];
        else if(count == k) return v[count-1];
        if(index < 0) index = 0;
        return v[count-1] / v[index];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */