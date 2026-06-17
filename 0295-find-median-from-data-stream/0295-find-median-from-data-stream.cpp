class MedianFinder {
public:
    vector<int> v;
    int size;
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size == 0){
            size++;
            v.push_back(num);
            return;
        }
        for(int i=0;i<size;i++){
            if(v[i] > num){
                size++;
                v.insert(v.begin()+i, num);
                return;
            }
        }
        size++;
        v.push_back(num);
    }
    
    double findMedian() {
        int n = size;
        int mid = n / 2;
        bool odd = n % 2 == 1;
        
        return odd ? (double)v[mid] : ((double)(v[mid] + v[mid-1])/2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */