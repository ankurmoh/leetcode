class Solution {
public:
    bool canPermutePalindrome(string s) {
       map<char,int>mp;
        int i,len=s.length(),con=0;
        for(i=0;i<len;i++)
            mp[s[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2==1)
                con++;
        }
        if(con<=1)
            return true;
        return false;
    }
};
