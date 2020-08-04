class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int i,len=s.length(),j=0;
        string temp="";
        stack<int>st;
        if(len==0)
            return "";
        for(i=0;i<len;i++)
        {
            if(s[i]=='(')
                st.push(i);
            else if((s[i]==')') && (!st.empty()))
                st.pop();
            else if((s[i]==')')&&(st.empty()))
                s[i]='*';
        }
        while(!st.empty())
        {
            s[st.top()]='*';
            st.pop();
        }
        for(i=0;i<len;i++)
        {
            if(s[i]!='*')
                s[j++]=s[i];
        }
        s[j]='\0';
        return s;
    }
};
