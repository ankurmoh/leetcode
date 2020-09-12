class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0)
            return "";
        if((numRows == 1) || (numRows >= s.length()))
            return s;
        vector<string>res(numRows);
        int i,len=s.length(),c=0,current=0;
        bool goingup=true;
        for(i=0;i<len;i++)
        {
            res[current]=res[current]+s[i];
            if((current==0) || (current==numRows-1))
                goingup = !goingup;
            if(!goingup)
                current=current+1;
            else
                current=current-1;
        }
        len=res.size();
        string ans="";
        for(i=0;i<len;i++)
            ans=ans+res[i];
        return ans;
    }
};
