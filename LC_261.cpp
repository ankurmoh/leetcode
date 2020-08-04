class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int i,sz=edges.size(),from,to,neigh;
        vector<vector<int>>adj(n+1);
        if(sz!=n-1)
            return false;
        vector<int>visited(n+1,0);
        for(i=0;i<sz;i++)
        {
            from=edges[i][0];
            to=edges[i][1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        queue<int>q;
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            from=q.front();
            q.pop();
            for(i=0;i<adj[from].size();i++)
            {
                neigh=adj[from][i];
                if(!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh]=1;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
                return false;
        }
        return true;
    }
};
