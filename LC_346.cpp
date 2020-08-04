class MovingAverage {
public:
    queue<int>q;
    int sz, sum;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz=size;
        sum=0;
    }

    double next(int val) {
        q.push(val);
        sum=sum+val;
        if(q.size()>sz)
        {
            sum=sum-q.front();
            q.pop();
        }
        return (1.0 *sum)/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
