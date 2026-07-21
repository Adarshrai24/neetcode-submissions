class MedianFinder {
public:
    //max heap
    priority_queue<int> pq1;
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {
        //max heap
        priority_queue<int> pq1;
        //min heap
        priority_queue<int, vector<int>, greater<int>> pq2;
    }
    
    void addNum(int num) {
        pq1.push(num);
        int temp = pq1.top();
        pq1.pop();
        pq2.push(temp);
        if (pq2.size() > pq1.size()) {
            temp = pq2.top();
            pq2.pop();
            pq1.push(temp);
        }
    }
    
    double findMedian() {
        if (pq1.size() != pq2.size()) {
            return (double)pq1.top();
        } else {
            return (double)(pq1.top() + pq2.top()) / 2.0;
        }
    }
};
