class Solution {
public:
    string minWindow(string s, string t) {
        if((s=="") || (t==""))
            return "";
        int left=0,right=0,len=t.length(),required,formed=0;
        map<char,int>req;
        map<char,int>window;
        for(left=0;left<len;left++)
            req[t[left]-'a']++;
        required = req.size();
        left=0;
        len=s.length();
        pair<int,int>ans = {-1,-1};
        while(right<len)
        {
            char ch=s[right];
            window[ch-'a']++;
            if((req.find(ch-'a')!=req.end()) && (req[ch-'a']==window[ch-'a']))
                formed++;
            while((left<=right) && (formed==required))
            {
               if(((ans.first==-1)&&(ans.second==-1)) || (right-left+1<ans.second))
               {
                   ans.first=left;
                   ans.second=right-left+1;
               }
                window[s[left]-'a']--;
                if((req.find(s[left]-'a')!=req.end()) && (req[s[left]-'a']>window[s[left]-'a']))
                    formed--;
                left++;
            }
            right++;
        }
        if(ans.second==-1)
            return "";
        return s.substr(ans.first,ans.second);
    }
};
