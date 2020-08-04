class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {

    }

    int ping(int t) {
        if(q.empty())
        {
            q.push(t);
            return 1;
        }
        while(!q.empty())
        {
            if(t-q.front()>3000)
                q.pop();
            else
                break;
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
