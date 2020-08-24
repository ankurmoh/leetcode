class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        vector<vector<int>>po;
        int i,sz = points.size(),x,y;
        double dist,fron;
        unordered_map<double, vector<pair<int,int>> >mp;
        priority_queue<double>pq;
        for(i=0;i<sz;i++)
        {
            x = points[i][0];
            y = points[i][1];
            dist = sqrt(x*x + y*y);
            if(pq.size()<K)
            {
                pq.push(dist);
                mp[dist].push_back(make_pair(x,y));
            }
            else if(pq.size()>=K)
            {
                if(dist<pq.top())
                {
                    mp.erase(pq.top());
                    pq.pop();
                    pq.push(dist);
                    mp[dist].push_back(make_pair(x,y));
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<pair<int,int>>v = it->second;
            for(i=0;i<v.size();i++)
                po.push_back({v[i].first,v[i].second});
        }
        return po;
    }
};
