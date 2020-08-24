class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
       vector<vector<int>>res;
        map< vector<vector<int>> , bool >st;
        int i,j,sz=grid.size(),sz1=grid[0].size();
        if(sz==0)
            return 0;
        for(i=0;i<sz;i++)
        {
            for(j=0;j<sz1;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,i,j,grid,res);
                    st[res]=true;
                    res.clear();
                }
            }
        }
        return st.size();
    }
    void dfs(int& i0,int& j0,int x,int y,vector<vector<int>>& grid,vector<vector<int>>& res)
    {
        if((x<0)||(x>=grid.size()) || (y<0) || (y>=grid[0].size()) || (grid[x][y]!=1))
            return;
        grid[x][y]=0;
        res.push_back({i0-x,j0-y});
        dfs(i0,j0,x+1,y,grid,res);
         dfs(i0,j0,x-1,y,grid,res);
         dfs(i0,j0,x,y+1,grid,res);
         dfs(i0,j0,x,y-1,grid,res);
    }
};
    
