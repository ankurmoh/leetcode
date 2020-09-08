class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n,i,j,res=0;
        if(m>0)
            n=matrix[0].size();
        else
            return 0;
        /*vector<vector<int>>dp(m,vector<int>(n));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else
                {
                    if((i==0) || (j==0))
                        dp[i][j]=1;
                    else
                        dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
                }
                res=max(res,dp[i][j]);
            }
        }
        return res*res;*/
        vector<vector<int>>dp(2,vector<int>(n,0));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                    dp[i%2][j]=0;
                else
                {
                    if (j==0)
                        dp[i%2][j]=1;
                    else
                        dp[i%2][j]=min(dp[(i+1)%2][j],min(dp[(i+1)%2][j-1],dp[i%2][j-1])) + 1;
                }
                res=max(res,dp[i%2][j]);
            }
        }
        return res*res;
    }
};
