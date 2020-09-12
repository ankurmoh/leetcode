class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        /*int sz=costs.size();
        if(sz==0)
            return 0;
        int i,j,x,mini,k=costs[0].size();
        vector<vector<int>>dp(sz+1,vector<int>(k+1,0));
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
        return mini;*/
        int i,n = costs.size(),k,res=INT_MAX,j,firstmin,secondmin;
        if(n==0)
            return 0;
        k = costs[0].size();
        for(i=1;i<n;i++)
        {
            firstmin=INT_MAX;
            secondmin=INT_MAX;
            for(j=0;j<k;j++)
            {
                if((firstmin == INT_MAX) || (costs[i-1][j]<costs[i-1][firstmin]))
                {
                    secondmin=firstmin;
                    firstmin=j;
                }
                else if((secondmin==INT_MAX) || (costs[i-1][j]<costs[i-1][secondmin]))
                    secondmin =j;
            }
            for(j=0;j<k;j++)
            {
                if(j==firstmin)
                    costs[i][j] = costs[i][j] + costs[i-1][secondmin];
                else
                    costs[i][j] = costs[i][j] + costs[i-1][firstmin];
            }
        }
        for(i=0;i<k;i++)
            res=min(res,costs[n-1][i]);
        return res;
    }
};
