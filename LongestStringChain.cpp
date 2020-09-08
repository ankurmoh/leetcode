class Solution {
public:
    int longestStrChain(vector<string>& words) {
       unordered_map<string,int>dp;
        int i,sz=words.size(),j,len,res=0;
        string temp;
        sort(words.begin(),words.end(),[](const string s1, const string s2) {
            return s1.length()<s2.length();
        });
        for(i=0;i<sz;i++)
        {
            len=words[i].length();
            dp[words[i]]=1;
            for(j=0;j<len;j++)
            {
                temp = words[i].substr(0,j) + words[i].substr(j+1);
                dp[words[i]]=max(dp[words[i]],dp[temp]+1);
                res=max(res,dp[words[i]]);
            }
        }
        return res;
    }
};mm
