class Solution {
public:
    int minDistance(string word1, string word2) {
        int i,j,len1=word1.length(),len2=word2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (len1+len2-2*dp[len1][len2]);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
       int len1=word1.length(),len2=word2.length(),i,j;
        vector<vector<int>>dp(len1+5,vector<int>(len2+5,0));
        for(i=1;i<=len1;i++)
            dp[i][0]=i;
        for(j=1;j<=len2;j++)
            dp[0][j]=j;
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
