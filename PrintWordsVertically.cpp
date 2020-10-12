class Solution {
public:
    vector<string> printVertically(string s) {
        int i,len=s.length(),maxlen=0,len1,j;
        vector<string>words;
        string temp="";
        for(i=0;i<len;i++)
        {
            if(s[i]!=' ')
                temp=temp+s[i];
            else if(s[i]==' ')
            {
                if(temp!="")
                {
                    words.push_back(temp);
                    if(maxlen<temp.length())
                        maxlen=temp.length();
                }
                temp="";
            }
        }
        if(temp!="")
        {
            words.push_back(temp);
            if(maxlen<temp.length())
                maxlen=temp.length();
        }
        temp="";
        vector<string>res(maxlen);
        len=words.size();
        for(i=0;i<len;i++)
        {
            temp=words[i];
            len1=temp.length();
            for(j=0;j<len1;j++)
            {
                res[j]=res[j]+temp[j];
            }
            for(;j<maxlen;j++)
                res[j]=res[j]+" ";
        }
        for(i=0;i<maxlen;i++)
        {
            temp=res[i];
            len1=temp.length();
            for(j=len1-1;(j>=0 && temp[j]==' ');j--);
            res[i]=temp.substr(0,j+1);
        }
        return res;
    }
};
