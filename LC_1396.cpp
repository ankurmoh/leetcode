class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        /*vector<vector<int>>graph(n);
        int i,sz=manager.size(),time,res=INT_MIN,src,fron;
        for(i=0;i<sz;i++)
        {
            if(manager[i]==-1)
                continue;
            graph[manager[i]].push_back(i);
        }
        src=headID;
        time=0;
        queue< pair<int,int> >q;
        q.push(make_pair(src,time));
        vector<int>visited(n,0);
        visited[src]=1;
        while(!q.empty())
        {
            fron = q.front().first;
            time = q.front().second;
            res = max(res, time);
            q.pop();
            for(i=0;i<graph[fron].size();i++)
            {
                if(!visited[graph[fron][i]])
                {
                    visited[graph[fron][i]]=1;
                    q.push(make_pair(graph[fron][i],time+informTime[fron]));
                }
            }
        }
        return res;*/
        int i,sz=manager.size(),fron,neighbor,time,maxdist = INT_MIN;
        vector<vector<pair<int,int>>>graph(n);
        for(i=0;i<sz;i++)
        {
            if(i==headID)
                continue;
            graph[manager[i]].push_back(make_pair(i,informTime[manager[i]]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push(make_pair(informTime[headID],headID));
        vector<int>dist(n,INT_MAX);
        dist[headID]=0;
        while(!pq.empty())
        {
            fron = pq.top().second;
            pq.pop();
            for(i=0;i<graph[fron].size();i++)
            {
                neighbor = graph[fron][i].first;
                time = graph[fron][i].second;
                if((dist[neighbor]==INT_MAX) || (dist[neighbor]>dist[fron] + time))
                {
                    dist[neighbor]=dist[fron]+time;
                    pq.push(make_pair(dist[neighbor],neighbor));
                }
            }
        }
        for(i=0;i<n;i++)
        {
            maxdist=max(maxdist,dist[i]);
        }
        return maxdist;
    }
};
