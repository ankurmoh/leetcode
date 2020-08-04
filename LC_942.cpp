class Solution {
public:
    vector<int> diStringMatch(string S) {
        int mini=0,maxi=S.length(),i,len=S.length();
        vector<int>res;
        for(i=0;i<len;i++)
        {
            if(S[i]=='I')
            {
                res.push_back(mini);
                mini++;
            }
            else if(S[i]=='D')
            {
                res.push_back(maxi);
                maxi--;
            }
        }
        res.push_back(mini);
        return res;
    }
};
