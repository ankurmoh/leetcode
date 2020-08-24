class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int i,len=num.length();
        for(i=0;i<len;i++)
        {
            while((!s.empty()) && (k>0) && (s.top()>num[i]))
            {
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        while(k>0)
        {
            s.pop();
            k--;
        }
        string temp = "";
        while(!s.empty())
        {
            temp=s.top() + temp;
            s.pop();
        }
        len=temp.length();
        if(temp == "")
            return "0";
        for(i=0;temp[i]=='0' && i<=len-2;i++);
        return temp.substr(i);
    }
};
