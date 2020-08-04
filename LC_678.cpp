class Solution {
public:
    bool checkValidString(string s) {
       stack<int>a;
        stack<int>b;
        int i,len=s.length();
        for(i=0;i<len;i++)
        {
            if(s[i]=='(')
                a.push(i);
            else if(s[i]=='*')
                b.push(i);
            else
            {
                if((a.empty()) && (b.empty()))
                    return false;
                else if(!a.empty())
                    a.pop();
                else if(!b.empty())
                    b.pop();
            }
        }
        while(!a.empty() && !b.empty())
        {
            if(a.top()>b.top())
                return false;
            a.pop();
            b.pop();
        }
        return a.empty();
    }
};
