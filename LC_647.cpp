class Solution {
public:
    int countSubstrings(string s)
    {
        if(s=="")
            return 0;
        int i,len=s.length(),con=0;

        for(i=0;i<len;i++)
            con=con+extend(s,i,i)+extend(s,i,i+1);

        return con;
    }
    int extend(string s, int left, int right)
    {
        int count=0;
        while((left>=0) && (right<s.length()) && (s[left]==s[right]))
        {
            count++;
           // cout<<s.substr(left,right-left+1)<<endl;
            left--;
            right++;
        }
        return count;
    }
};
