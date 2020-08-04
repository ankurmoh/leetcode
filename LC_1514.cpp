class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>graph(n);
        int i,front,neighbor,sz = edges.size();
        double inverselog;
        for(i=0;i<sz;i++)
        {
            inverselog = -log(succProb[i]);
            graph[edges[i][0]].push_back(make_pair(edges[i][1],inverselog));
            graph[edges[i][1]].push_back(make_pair(edges[i][0],inverselog));
        }
        vector<double>dist(n,999999.99);
        dist[start]=0;
        priority_queue< pair<double,int>, vector< pair<double,int> >, greater< pair<double,int> >>pq;
        pq.push(make_pair(0,start));
        while(!pq.empty())
        {
            front = pq.top().second;
            pq.pop();
            for(i=0;i<graph[front].size();i++)
            {
                neighbor = graph[front][i].first;
                if(dist[neighbor]>dist[front] + graph[front][i].second)
                {
                    dist[neighbor] = dist[front] + graph[front][i].second;
                    pq.push(make_pair(dist[neighbor], neighbor));
                }
            }
        }
        if(dist[end]==999999.99)
            return 0;
        return 1.0/exp(dist[end]);
    }
};
