class Solution {
public:
    bool dfs(vector<vector<int>>& graph,unordered_map<int,int>& color,int ind,int col)
    {
        color[ind]=col;
        int i,sz=graph[ind].size(),neigh;
        for(i=0;i<sz;i++)
        {
            neigh = graph[ind][i];
            if(color.find(neigh)!=color.end())
            {
                if(color[neigh]==color[ind])
                    return false;
            }
            else if(color.find(neigh)==color.end())
            {
                if(dfs(graph,color,neigh,1-color[ind]) == false)
                    return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
    unordered_map<int,int>color;
     int i,sz=dislikes.size(),fron,j;
        vector < vector <int > >graph(2002);
        for(i=0;i<sz;i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(j=1;j<=N;j++)
        {
            if((color.find(j)==color.end()) && (!dfs(graph,color,j,1)))
            {
                return false;
            }
        }
        return true;
    /*    for(j=1;j<=N;j++)
        {
        if(color.find(j)!=color.end())
            continue;
        queue<int>q;
        q.push(j);
        color[j]=1;

        while(!q.empty())
        {
            fron=q.front();
            q.pop();
            sz=graph[fron].size();
            for(i=0;i<sz;i++)
            {
                if(color.find(graph[fron][i])==color.end())
                {
                    q.push(graph[fron][i]);
                    color[graph[fron][i]]=1-color[fron];
                }
                else
                {
                    if(color[graph[fron][i]]==color[fron])
                        return false;
                }
            }
        }
        }
        return true;*/
    }
};
