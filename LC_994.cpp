class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue< pair<int,int> >q;
        vector<int>xdir={0,0,1,-1};
        vector<int>ydir={1,-1,0,0};
        pair<int,int>fron;
        int sz=grid.size(),x,y,min=0;
        if(sz==0)
            return 0;
        int sz1=grid[0].size(),i,j;
        for(i=0;i<sz;i++)
        {
            for(j=0;j<sz1;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty())
        {
            int con = q.size();
            for(j=0;j<con;j++)
            {
            fron=q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                x=fron.first+xdir[i];
                y=fron.second+ydir[i];
                if((x>=0) && (x<sz) && (y>=0) && (y<sz1) && (grid[x][y]==1))
                {
                    grid[x][y]=2;
                    q.push(make_pair(x,y));
                }
            }
            }
            min++;
        }
        for(i=0;i<sz;i++)
            for(j=0;j<sz1;j++)
                if(grid[i][j]==1)
                    return -1;
        return max(min-1,0);
    }
};
