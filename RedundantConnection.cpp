class Solution {
public:
    bool dfs(int src,int dest,vector<vector<int>>& graph,vector<int>& visited)
    {
        visited[src]=1;
        if(src==dest)
            return true;
        int i,sz=graph[src].size();
        for(i=0;i<sz;i++)
        {
            if(!visited[graph[src][i]])
            {
                if(dfs(graph[src][i],dest,graph,visited))
                    return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int i,sz=edges.size(),to,from;
        if(sz==0)
            return vector<int>();
        vector<int>ans;
        vector<int>visited(sz+1);
        vector<vector<int>>graph(sz+1,vector<int>(sz+1));
        for(i=0;i<sz;i++)
        {
            fill(visited.begin(),visited.end(),0);
            to=edges[i][0];
            from=edges[i][1];
            if (dfs(to,from,graph,visited))
            {
               ans = edges[i];
              // return ans;
            }
            graph[to].push_back(from);
            graph[from].push_back(to);
        }
        return ans;
    }
};
