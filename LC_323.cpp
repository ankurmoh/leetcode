class Solution {
public:
 /*   void dfs(int node, vector<int>& visited, vector<vector<int>>& adj)
    {
        visited[node]=1;
        int i,neigh;
        for(i=0;i<adj[node].size();i++)
        {
            neigh=adj[node][i];
            if(!visited[neigh])
                dfs(neigh,visited,adj);
        }
        return ;
    } */
    int countComponents(int n, vector<vector<int>>& edges) {
        int i,sz=edges.size(),from,to,con=0,j,neigh;
        vector<vector<int>>adj(n+1);
        vector<int>visited(n+1,0);
        for(i=0;i<sz;i++)
        {
            to=edges[i][0];
            from=edges[i][1];
            adj[to].push_back(from);
            adj[from].push_back(to);
        }
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                con++;
                queue<int>q;
                q.push(i);
                visited[i]=1;
                while(!q.empty())
                {
                    from=q.front();
                    q.pop();
                    for(j=0;j<adj[from].size();j++)
                    {
                        neigh=adj[from][j];
                        if(!visited[neigh])
                        {
                            visited[neigh]=1;
                                    q.push(neigh);
                        }
                    }
                }
                //dfs(i,visited,adj);

            }
        }
        return con;
    }
};
