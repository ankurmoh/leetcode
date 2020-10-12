class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int i,j,sz1=grid.size(),sz2;
        if(sz1==0)
            return 0;
        sz2 = grid[0].size();
        vector<vector<long long int>>min1(sz1,vector<long long int>(sz2,0));
        vector<vector<long long int>>max1(sz1,vector<long long int>(sz2,0));
        min1[0][0]=grid[0][0];
        max1[0][0]=grid[0][0];
        for(i=1;i<sz1;i++)
        {
            min1[i][0]=grid[i][0]*min1[i-1][0];
            max1[i][0]=grid[i][0]*max1[i-1][0];
        }
        for(i=1;i<sz2;i++)
        {
            min1[0][i]=grid[0][i]*min1[0][i-1];
            max1[0][i]=grid[0][i]*max1[0][i-1];
        }
        for(i=1;i<sz1;i++)
        {
            for(j=1;j<sz2;j++)
            {
                if(grid[i][j]==0)
                {
                    min1[i][j]=0;
                    max1[i][j]=0;
                }
                else if(grid[i][j]>0)
                {
                    max1[i][j]=grid[i][j]*max(max1[i-1][j],max1[i][j-1]);
                    min1[i][j]=grid[i][j]*min(min1[i-1][j],min1[i][j-1]);
                }
                else
                {
                    max1[i][j]=grid[i][j]*min(min1[i-1][j],min1[i][j-1]);
                    min1[i][j]=grid[i][j]*max(max1[i-1][j],max1[i][j-1]);
                }
            }
        }
        if(max1[sz1-1][sz2-1]<0)
            return -1;
        return max1[sz1-1][sz2-1]%1000000007;
    }
};
