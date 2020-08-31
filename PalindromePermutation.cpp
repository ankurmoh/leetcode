class Solution {
public:
    void permute(string half,vector<string>& ans,int begin,unordered_set<string>& mp,string odd)
    {
        int i,len=half.length();
        if(begin==len)
        {
            if(mp.count(half)==0)
            {
                mp.insert(half);
                string temp=half;
                reverse(temp.begin(),temp.end());
                ans.push_back(half+odd+temp);
            }
            return;
        }
        for(i=begin;i<len;i++)
        {
            swap(half[begin],half[i]);
            permute(half,ans,begin+1,mp,odd);
            swap(half[begin],half[i]);
        }
    }
    vector<string> generatePalindromes(string s)
    {
       vector<int>freq(256,0);
        vector<string>ans;
       int i,len=s.length(),con=0,len1;
        bool flag=false;
        for(i=0;i<len;i++)
            freq[s[i]]++;
        for(i=0;i<=255;i++)
        {
            if(freq[i]%2==1)
                con++;
        }
        if(con>1)
            return ans;
        string half="",odd="",palin,reversehalf;
        for(i=0;i<=255;i++)
        {
            if(freq[i]%2==1)
                odd=string(1, char(i));
            if(freq[i]>0)
                half=half+string(freq[i]/2, char(i));
        }
        //unordered_set<string>mp;
        //permute(half,ans,0,mp,odd);
        len1=half.length();
        do
        {
            reversehalf=half;
            reverse(reversehalf.begin(),reversehalf.end());
            palin= half + odd + reversehalf;
            ans.push_back(palin);
        }while(next_permutation(half.begin(),half.end()));
        return ans;
    }
};
