class Solution {
public:
    int min1(int a,int b,int c)
    {
        return min(a,min(b,c));
    }
    int numberOfSubstrings(string s) {
        /*int left=0,len=s.length(),right=0,con=0;
        vector<int>freq(26,0);
        for(right=0;right<len;right++)
        {
            freq[s[right]-'a']++;
            while(freq[0] && freq[1] && freq[2])
            {
                freq[s[left]-'a']--;
                left++;
            }
            con = con + left;
        }
        return con;*/
        int l1=-1,l2=-1,l3=-1,i,len=s.length(),con=0;
        for(i=0;i<len;i++)
        {
            if(s[i]=='a')
                l1=i;
            if(s[i]=='b')
                l2=i;
            if(s[i]=='c')
                l3=i;
            con = con + min1(l1,l2,l3) + 1;
        }
        return con;
    }
};
