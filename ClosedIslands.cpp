class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x,int y)
    {
         if((x<0)||(x>=grid.size())||(y<0)||(y>=grid[0].size())||(visited[x][y]==1)||(grid[x][y]!=0))
                    return;
        visited[x][y]=1;
        int i;
        for(i=0;i<4;i++)
        {
            dfs(grid,visited,x+dir[i][0],y+dir[i][1]);
        }
    }
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, queue< pair<int,int> >& q )
    {
        int i,x,y,newx,newy;
        while(!q.empty())
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            //cout<<x<<
            for(i=0;i<4;i++)
            {
                newx=x+dir[i][0];
                newy=y+dir[i][1];
                if((newx<0)||(newx>=grid.size())||(newy<0)||(newy>=grid[0].size())||(visited[newx][newy]==1)||(grid[newx][newy]!=0))
                    continue;
                visited[newx][newy]=1;
                q.push(make_pair(newx,newy));
                grid[newx][newy]=1;
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int i,j,m=grid.size(),n,res=0,con=0;
        if(m==0)
            return res;
         n=grid[0].size();
         vector<vector<int>>visited(m,vector<int>(n,0));
         queue< pair<int,int> >q;
        for(i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                visited[i][0]=1;
                q.push(make_pair(i,0));
                grid[i][0]=1;
            }
            if(grid[i][n-1]==0)
            {
                visited[i][n-1]=1;
                q.push(make_pair(i,n-1));
                grid[i][n-1]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            if((grid[0][i]==0) && (!visited[0][i]))
            {
                visited[0][i]=1;
                q.push(make_pair(0,i));
                grid[0][i]=1;
            }
            if((grid[m-1][i]==0) && (!visited[m-1][i]))
            {
                visited[m-1][i]=1;
                q.push(make_pair(m-1,i));
                grid[m-1][i]=1;
            }
        }
        bfs(grid,visited,q);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                visited[i][j]=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if((grid[i][j]==0) && (!visited[i][j]))
                {
                    con++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return con;
    }
};
