class Solution {
public:
    string longestPalindrome(string s) {
        int i,len=s.length(),j,x,start=0,maxlen=1;
        vector<vector<int>>dp(len+1, vector<int>(len+1,0));
        for(i=0;i<len;i++)
            dp[i][i]=1;
        for(i=0;i<len-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start=i;
                maxlen=2;
            }
        }
        for(x=3;x<=len;x++)
        {
            for(i=0;i<=len-x;i++)
            {
                j=i+x-1;
                if((s[i]==s[j]) && (dp[i+1][j-1]==1))
                {
                    dp[i][j]=1;
                    if(maxlen<x)
                    {
                        maxlen=x;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
