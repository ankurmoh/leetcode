class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {

        int i,sz1=words1.size(),sz2=words2.size(),sz3=pairs.size(),flag=0,con,j;
        unordered_map<string, unordered_set<string> >mp;
        string to,from;
        if(sz1!=sz2)
            return false;
        for(i=0;i<sz3;i++)
        {
            to=pairs[i][0];
            from=pairs[i][1];
            mp[to].insert(from);
            mp[from].insert(to);
        }
        for(i=0;i<sz1;i++)
        {
            to=words1[i];
            from=words2[i];
            if((to==from) || (mp[to].count(from)))
                continue;
            else
            {
              return false;
            }
        }

        return true;
    }
};
