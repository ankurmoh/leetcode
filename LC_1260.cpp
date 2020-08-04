class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int i,j,m=grid.size(),n=grid[0].size(),ind;
        vector<vector<int>>res(m,vector<int>(n));
        res=grid;
        for(ind=0;ind<k;ind++)
        {
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if((i<m) && (j+1<n))
                        res[i][j+1]=grid[i][j];
                    else if((i+1<m) && (j==n-1))
                        res[i+1][0]=grid[i][j];
                    else if((i==m-1) && (j==n-1))
                        res[0][0]=grid[i][j];
                }
            }
            grid=res;
        }
        return res;
    }
};
