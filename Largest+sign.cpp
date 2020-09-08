class Solution {
public:
    int min1(int a,int b,int c,int d)
    {
        return min(a,min(b,min(c,d)));
    }
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>>left(N,vector<int>(N,0));
        vector<vector<int>>right(N,vector<int>(N,0));
        vector<vector<int>>up(N,vector<int>(N,0));
        vector<vector<int>>down(N,vector<int>(N,0));
        vector<vector<int>>grid(N,vector<int>(N,N));
        int i,j,sz=mines.size(),res=0,l,r,u,d;
        for(i=0;i<sz;i++)
        {
            grid[mines[i][0]][mines[i][1]]=0;
        }
        for(i=0;i<N;i++)
        {
            l=0;
            for(j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                    l=0;
                else
                    l=l+1;
                grid[i][j]=min(grid[i][j],l);
            }
            r=0;
            for(j=N-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                    r=0;
                else
                    r=r+1;
                grid[i][j]=min(grid[i][j],r);
            }
            u=0;
            for(j=0;j<N;j++)
            {
                if(grid[j][i]==0)
                    u=0;
                else
                    u=u+1;
                grid[j][i]=min(grid[j][i],u);
            }
            d=0;
            for(j=N-1;j>=0;j--)
            {
                if(grid[j][i]==0)
                    d=0;
                else
                    d=d+1;
                grid[j][i]=min(grid[j][i],d);
            }
            // for(j=0;j<N;j++)
            // {
            //     if(grid[i][j]==0)
            //         l=0;
            //     else
            //         l=l+1;
            //     left[i][j]=l;
            // }
            // r=0;
            // for(j=N-1;j>=0;j--)
            // {
            //     if(grid[i][j]==0)
            //         r=0;
            //     else
            //         r=r+1;
            //     right[i][j]=r;
            // }
            // u=0;
            // for(j=0;j<N;j++)
            // {
            //     if(grid[j][i]==0)
            //         u=0;
            //     else
            //         u=u+1;
            //     up[j][i]=u;
            // }
            // d=0;
            // for(j=N-1;j>=0;j--)
            // {
            //     if(grid[j][i]==0)
            //         d=0;
            //     else
            //         d=d+1;
            //     down[j][i]=d;
            // }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                //grid[i][j]=min1(left[i][j],right[i][j],up[i][j],down[i][j]);
                res=max(res,grid[i][j]);
            }
        }
        return res;
    }
};
