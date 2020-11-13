class Solution {
public:
    int maxDepth(string s) {
        int i,len=s.length(),maxi=0;
        stack<char>st;
        for(i=0;i<len;i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            maxi=max(maxi,int(st.size()));
            if((s[i]==')') && (!st.empty()) && (st.top() =='('))
                st.pop();
        }
        return maxi;
    }
};
