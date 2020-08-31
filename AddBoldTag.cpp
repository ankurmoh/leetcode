class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int i,j,sz=words.size(),len=S.length(),start,end,k,len1;
        vector<int>flag(len+1,0);
        string temp;
        for(i=0;i<sz;i++)
        {
            temp=words[i];
            len1=temp.length();
            for(j=0;j<len;j++)
            {
                if(S.find(temp,j)!=string::npos)
                {
                    start=S.find(temp,j);
                    end=start+len1-1;
                    for(k=start;k<=end;k++)
                        flag[k]=1;
                }
                else
                    break;
            }
        }
        int status=0;
        temp="";
        for(i=0;i<len;i++)
        {
            if((flag[i]==1) && (status==0))
            {
                temp=temp+"<b>";
                status=1;
            }
            else if((status==1) && (flag[i]==0))
            {
                temp=temp+"</b>";
                status=0;
            }
            temp=temp+S[i];
        }
        if(status)
            temp=temp+"</b>";
            /*
            i=0;
       while(i<len)
       {
           if(flag[i]==0)
           {
               temp=temp+s[i];
               i++;
           }
           else
           {
               temp=temp+"<b>";
               j=i;
               while((j<len) && (flag[j]==1))
                   temp=temp+s[j++];
               temp=temp+"</b>";
               i=j;
           }
       }
            */
        return temp;
    }
};
