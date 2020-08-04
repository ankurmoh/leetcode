class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int sz=costs.size();
        if(sz==0)
            return 0;
        int i,j,x,mini,k=costs[0].size();
        vector<vector<int>>dp(sz,vector<int>(k,0));
        for(i=0;i<k;i++)
            dp[0][i]=costs[0][i];
        for(i=1;i<sz;i++)
        {
            for(j=0;j<k;j++)
            {
                mini=INT_MAX;
                for(x=0;x<k;x++)
                {
                    if(x==j)
                        continue;
                    mini=min(mini,dp[i-1][x]);
                }
                dp[i][j] = costs[i][j] + mini;
            }
        }
        mini=INT_MAX;
        for(j=0;j<k;j++)
            mini = min(mini, dp[sz-1][j]);
        return mini;
    }
};
