class MedianFinder {
public:
    /** initialize your data structure here. */

    vector<int>res;
        priority_queue<int>low;
    priority_queue<int,vector<int>,greater<int>>high;
    MedianFinder() {

    }

    void addNum(int num)
    {
        // if(res.size()==0)
        //     res.push_back(num);
        // else
        //     res.insert(lower_bound(res.begin(),res.end(),num),num);
        low.push(num);
        high.push(low.top());
        low.pop();
        if(low.size()<high.size())
        {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
       // if(res.size()%2)
       //     return res[res.size()/2];
       //  return 0.5*(res[res.size()/2 - 1] + res[res.size()/2]);
        if(low.size()>high.size())
        {
            return 1.0*low.top();
        }
        return 0.5*(low.top() + high.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
