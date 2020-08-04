class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
       int sz=grid.size(),sz1=grid[0].size(),i,j,maxres=INT_MIN;
       if(sz==0)
           return 0;
       vector < vector < bool > > visited(sz,vector < bool > (sz1,false));
       for(i=0;i<sz;i++)
       {
           for(j=0;j<sz1;j++)
           {
               if((grid[i][j]==1) && (visited[i][j]==false))
                   maxres=max(maxres,dfs(i,j,sz,sz1,grid,visited));
           }
       }
        return max(maxres,0);
    }
    int dfs(int x,int y,int siz1,int siz2,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
       if((x<0)||(x>=siz1)||(y<0)||(y>=siz2)||(visited[x][y]==true)||(grid[x][y]!=1))
           return 0;
        visited[x][y]=true;
        return 1+dfs(x+1,y,siz1,siz2,grid,visited)+dfs(x-1,y,siz1,siz2,grid,visited)+dfs(x,y+1,siz1,siz2,grid,visited)+dfs(x,y-1,siz1,siz2,grid,visited);
    }
};
