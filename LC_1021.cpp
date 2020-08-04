class Solution {
public:
    string removeOuterParentheses(string S) {
        int i,len=S.length(),left=0,flag=0;
        string res="",ans="";
        for(i=0;i<len;i++)
        {
            if((S[i]=='(')&&(flag==0))
            {
                left++;
                flag=1;
            }
            else if(S[i]=='(')
            {
                res=res+S[i];
                left++;
            }
            else if(S[i]==')')
            {
                left--;
            if(left>0)
                res=res+')';
            else if(left==0)
            {
                flag=0;
                if(res!="")
                    ans=ans+res;
                res="";
            }
            }
        }
        return ans;
    }
};
