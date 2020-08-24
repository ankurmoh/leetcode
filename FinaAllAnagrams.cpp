class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        vector<int>st(26,0);
        vector<int>pt(26,0);
        int i,len1=s.length(),len2=p.length();
        if(len1<len2)
            return res;
        for(i=0;i<len2;i++)
        {
            st[s[i]-'a']++;
            pt[p[i]-'a']++;
        }
        if(st==pt)
            res.push_back(0);
        for(i=len2;i<len1;i++)
        {
            st[s[i]-'a']++;
            st[s[i-len2]-'a']--;
            if(st==pt)
                res.push_back(i-len2+1);
        }
        return res;
    }
};
