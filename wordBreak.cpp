class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(99999,false);
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        string prefix,suffix;
        int i,len=s.length(),j;
        for(i=1;i<=len;i++)
        {
            prefix=s.substr(0,i);
            if((dp[i]==false)&&(st.count(prefix)))
                dp[i]=true;
            if(dp[i]==true)
            {
                for(j=i+1;j<=len;j++)
                {
                    suffix=s.substr(i,j-i);
                    if((dp[j]==false)&&(st.count(suffix)))
                        dp[j]=true;
                }
            }
        }
        return dp[len];
    }
};


        int fron,end;
        queue<int>q;
        vector<int>visited(s.length(),0);
        string temp;
        q.push(0);
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        while(!q.empty())
        {
            fron = q.front();
            q.pop();
            if(visited[fron]==0)
            {
                for(end=fron+1;end<=s.length();end++)
                {
                    temp = s.substr(fron,end-fron);
                    if(st.count(temp)) 
                    {
                        q.push(end);
                        if(end==s.length())
                            return true;
                    }
                }
                visited[fron]=1;
            }
        }
        return false;
