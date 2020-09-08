class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int i=0,sz=events.size(),con=0,day;
        sort(events.begin(),events.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        for(day = 1;day<= 100000;day++)
        {
            while((!pq.empty()) && (pq.top()<day))
                pq.pop();
            while((i<sz) && (events[i][0]==day))
            {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty())
            {
                pq.pop();
                con++;
            }
        }
        return con;
    }
};
