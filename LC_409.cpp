class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        if(s=="")
            return 0;
        int i,len=s.length(),flag=0,lenmax=0;
        for(i=0;i<len;i++)
            mp[s[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2==0)
                lenmax+=it->second;
            else if((it->second%2==1) )
            {
                flag=1;
                lenmax+=(it->second-1);
            }
        }
        if(flag)
            lenmax+=1;
        return lenmax;
    }
};
