import 'package:collection/collection.dart';
class MedianFinder {
  PriorityQueue<int> small = PriorityQueue<int>();
  PriorityQueue<int> large = PriorityQueue<int>((a, b) => b.compareTo(a));
  MedianFinder() {
  }
  
  void addNum(int num) {
    small.add(num);
    large.add(small.removeFirst());
    if(large.length > small.length){
        small.add(large.removeFirst());
    }
  }
  
  double findMedian() {
    return small.length > large.length ? small.first.toDouble() : (small.first + large.first) / 2;
  }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = MedianFinder();
 * obj.addNum(num);
 * double param2 = obj.findMedian();
 */