class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int i,j,len1=A.size(),len2=B.size(),maxlen=0;
        if((len1==0) || (len2==0))
            return 0;
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        for(i=0;i<=len1;i++)
        {
            for(j=0;j<=len2;j++)
            {
                if((i==0) || (j==0))
                    continue;
                if(A[i-1] == B[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    maxlen=max(maxlen,dp[i][j]);
                }
            }
        }
        return maxlen;
    }
};
