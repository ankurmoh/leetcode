class Solution {
public:
    bool isValid(string s) {
        int i,len=s.length();
        char tp;
     stack<char>st;
        for(i=0;i<len;i++)
        {
            if((s[i]=='(') || (s[i]=='[') || (s[i]=='{'))
                st.push(s[i]);
            else
            {
                if(st.empty()==true)
                    return false;
                else if(!st.empty())
                {
                tp=st.top();
                if(((tp=='(') && (s[i]==')')) || ((tp=='[') && (s[i]==']'))
                    || ((tp=='{') && (s[i]=='}') ) )
                        st.pop();
                else
                   return false;
                }
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};
