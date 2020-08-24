class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1=s1.length(),len2=s2.length(),i,j,val;
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        /*for(j=1;j<=len2;j++)
            dp[0][j]=dp[0][j-1] + s2[j-1];
        for(i=1;i<=len1;i++)
            dp[i][0]=dp[i-1][0] + s1[i-1];
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[len1][len2];*/
        for(j=len2-1;j>=0;j--)
            dp[len1][j]=dp[len1][j+1]+s2[j];
        for(i=len1-1;i>=0;i--)
            dp[i][len2]=dp[i+1][len2]+s1[i];
        for(i=len1-1;i>=0;i--)
        {
            for(j=len2-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                    dp[i][j]=dp[i+1][j+1];
                else
                    dp[i][j]=min(dp[i+1][j]+s1[i],dp[i][j+1]+s2[j]);
            }
        }
        return dp[0][0];
    }
};
