class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length(),len2=word2.length(),i,j,left,down,diag;
        vector<vector<int>>dp(len1+10,vector<int>(len2+10));
        for(i=0;i<=len1;i++)
            dp[i][0]=i;
        for(j=0;j<=len2;j++)
            dp[0][j]=j;
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                left=dp[i-1][j]+1;
                down=dp[i][j-1]+1;
                diag=dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1])
                    diag=diag+1;
                dp[i][j]=min(left,min(down,diag));
            }
        }
        return dp[len1][len2];
    }
};
