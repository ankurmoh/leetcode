class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>graph(N+1);
        int i,sz=connections.size(),fron,cost,res=0,neigh,wt;
        for(i=0;i<sz;i++)
        {
            graph[connections[i][0]].push_back(make_pair(connections[i][1],connections[i][2]));
            graph[connections[i][1]].push_back(make_pair(connections[i][0],connections[i][2]));
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        vector<int>visited(N+1,0);
        vector<int>distance(N+1,INT_MAX);
        distance[1]=0;
        pq.push(make_pair(0,1));
        while(!pq.empty())
        {
            fron = pq.top().second;
            cost = pq.top().first;
            pq.pop();
             visited[fron]=1;
            for(i=0;i<graph[fron].size();i++)
            {
                neigh = graph[fron][i].first;
                wt = graph[fron][i].second;
                if(((distance[neigh]>wt) || (distance[neigh]==INT_MAX)) && (!visited[neigh]))
                {
                    distance[neigh]=wt;
                    pq.push(make_pair(wt,neigh));
                }
            }
        }
        for(i=1;i<=N;i++)
        {
            if(distance[i]==INT_MAX)
                return -1;
            res=res+distance[i];
        }
        return res;
    }
};
