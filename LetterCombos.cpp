class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string>res;
        string key;
        int i,len=digits.length(),sz,sz1,j,k,dig;
        if(len==0)
            return res;
        res.push_back("");
        vector<string>mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(i=0;i<len;i++)
        {
            dig=digits[i]-'0';
            key=mp[dig];
            if(key=="")
                continue;
            vector<string>temp;
            sz=key.length();
            sz1=res.size();
            for(j=0;j<sz;j++)
            {
                for(k=0;k<sz1;k++)
                    temp.push_back(res[k]+key[j]);
            }
            res=temp;
        }
        return res;
    }
};
