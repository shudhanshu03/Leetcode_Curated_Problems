class MedianFinder {
public:
    priority_queue<int> fh;
    priority_queue<int,vector<int>,greater<int>> sh;
    MedianFinder(){
        
    }
    void addNum(int num) {
        fh.push(num);
        sh.push(fh.top());
        fh.pop();
        
        if(sh.size() > fh.size())
        {
            fh.push(sh.top());
            sh.pop();
        }
    }
    
    double findMedian() {
       if(fh.size()>sh.size())
           return fh.top();
       else{
           return (fh.top()+sh.top())/2.0;
       } 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */