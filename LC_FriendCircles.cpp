class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj)
    {
        visited[node]=1;
        int i,neigh,sz=adj[node].size();
        for(i=0;i<sz;i++)
        {
            neigh=adj[node][i];
            if(!visited[neigh])
                dfs(neigh,visited,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size(),i,j,con=0;
        vector<vector<int>>adj(n+1);
        vector<int>visited(n+1,0);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                con++;
                dfs(i,visited,adj);
            }
        }
        return con;
    }
};
