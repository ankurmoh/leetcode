class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.length()+2);
        int i,val1;
        string temp1,temp2;
        dp[0]=1;
        if(s[0]=='0')
            dp[1]=0;
        else
            dp[1]=1;
        for(i=2;i<=s.length();i++)
        {
            temp1=s.substr(i-1,1);
            temp2=s.substr(i-2,2);
            val1=stoi(temp1);
            if((val1>=1)&&(val1<=9))
                dp[i]=dp[i]+dp[i-1];
            val1=stoi(temp2);
            if((val1>=10)&&(val1<=26))
                dp[i]=dp[i]+dp[i-2];
        }
        return dp[s.length()];
    }
};
