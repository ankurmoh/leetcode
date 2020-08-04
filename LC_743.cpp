class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector< vector< pair<int,int> > >graph(N);
        int i,neighbor,front,curwt,sz=times.size(),maxwt=0;
        for(i=0;i<sz;i++)
            graph[times[i][0]-1].push_back(make_pair(times[i][1]-1,times[i][2]));
        vector<int>dist(N,INT_MAX);
        K=K-1;
        dist[K]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push(make_pair(0,K));
        while(!pq.empty())
        {
            front = pq.top().second;
            pq.pop();
            for(i=0;i<graph[front].size();i++)
            {
                neighbor = graph[front][i].first;
                curwt = graph[front][i].second;
                if(dist[neighbor] > dist[front] + curwt)
                {
                    dist[neighbor] = dist[front] + curwt;
                    pq.push(make_pair(dist[neighbor],neighbor));
                }
            }
        }
        for(i=0;i<N;i++)
            maxwt=max(maxwt,dist[i]);
        if(maxwt==INT_MAX)
            return -1;
        return maxwt;
    }
};
