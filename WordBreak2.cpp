class Solution {
public:
    vector<string> recurse(string s, vector<string>& wordDict,unordered_map<string, vector<string>>& memo)
    {
        vector<string>res;
        if(s=="")
        {
            res.push_back("");
            return res;
        }
        if(memo.find(s)!=memo.end())
            return memo[s];
        int i,sz=wordDict.size(),len;
        string temp;
        for(i=0;i<sz;i++)
        {
            temp = wordDict[i];
            len = temp.length();
            if(s.substr(0,len) == temp)
            {
                vector<string>substrings = recurse(s.substr(len), wordDict,memo);
                for(string word:substrings)
                {
                    if(word!="")
                        res.push_back(temp+" "+word);
                    else
                        res.push_back(temp+word);
                }
            }
        }
        memo[s]=res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> memo;
        return recurse(s,wordDict,memo);
    }
};
