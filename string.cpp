class Solution {
public:
    string reorganizeString(string S) {
        string ans="";
        string sortedans="";
        map<char,int>mp;
        int i,j,n=S.length(),flag=0,sz;
        for(i=0;i<n;i++)
            mp[S[i]]++;
        vector<pair<int,char>>v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>(n+1)/2)
                return "";
            v.push_back(make_pair(it->second,it->first));
        }
        sort(v.rbegin(),v.rend());
        sz=v.size();
        for(i=0;i<sz;i++)
        {
            string temp(v[i].first,v[i].second);
            sortedans=sortedans + temp;
        }
        n=sortedans.length();

        for ( i = 0, j = (n-1)/2+1; i <= (n-1)/2 ; ++i, ++j)
        {
                ans += sortedans[i];
               if(j<n)
                ans += sortedans[j];
        }

        return ans;
    }
};
