class MedianFinder {
    PriorityQueue<Integer> left = new PriorityQueue<>();
    PriorityQueue<Integer> right = new PriorityQueue<>(Collections.reverseOrder());
    int size = 0;
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        size++;
        left.add(num);
        right.add(left.remove());
        while(left.size() < right.size()){
            left.add(right.remove());
        }
    }
    
    public double findMedian() {
        return size % 2 == 0 ? (double)(left.peek() + right.peek()) / 2 : left.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */