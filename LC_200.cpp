class Solution {
public:
    vector<vector<int>>visit = {{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        int x,y,k,newx,newy;
        grid[i][j]=0;
        queue<pair<int,int>>q;
        q.push(make_pair(i,j));
        while(!q.empty())
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(k=0;k<4;k++)
            {
                newx=x+visit[k][0];
                newy=y+visit[k][1];
                if((newx>=0) && (newx<grid.size()) && (newy>=0) && (newy<grid[0].size()) && (grid[newx][newy]=='1')) {
                   grid[newx][newy]=0;
                    q.push(make_pair(newx,newy));
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() ==0)
            return 0;
        int con=0,i,j,len1=grid.size(),len2=grid[0].size();
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(grid[i][j]=='1')
                {
                    con++;
                    bfs(grid,i,j);
                }
            }
        }
        return con;
    }
};
