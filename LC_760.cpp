class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>>mp;
        int i,j,len=A.size(),sz;
        for(i=0;i<len;i++)
            mp[B[i]].push_back(i);
        vector<int>res;
        for(i=0;i<len;i++)
        {
            sz = mp[A[i]].size();
            res.push_back(mp[A[i]][sz-1]);
            mp[A[i]].pop_back();
        }
        return res;
    }
};
