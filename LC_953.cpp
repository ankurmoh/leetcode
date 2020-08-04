class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        int index[26]={0};
        int len=order.length(),sz=words.size(),minlen=-1,flag,j,i;
        string first,second;
        for(i=0;i<len;i++)
            index[order[i]-'a']=i+1;
        for(i=0;i<sz-1;i++)
        {
            first=words[i];
            second=words[i+1];
            minlen=min(first.length(),second.length());
            flag=0;
            for(j=0;j<minlen;j++)
            {
                if(index[first[j]-'a']<index[second[j]-'a'])
                {
                    flag=1;
                    break;
                }
                else if(index[first[j]-'a']>index[second[j]-'a'])
                    return false;
            }
            if(flag==1)
                continue;
            else if(flag==0)
            {
                if(first.length()>second.length())
                   return false;
            }
        }
        return true;
    }
};
