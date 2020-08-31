class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int i=0,sz=A.size(),j=0,sz1;
        vector<int>Bcopy = B;
        sort(A.begin(),A.end());
        sort(Bcopy.begin(),Bcopy.end());
        vector<int>res(sz);
        unordered_map<int, vector<int>>mp;
        queue<int>q;
        while(i<sz)
        {
            if(A[i]>Bcopy[j])
            {
                mp[Bcopy[j]].push_back(A[i]);
                i++;
                j++;
            }
            else
            {
                q.push(A[i]);
                i++;
            }
        }
        for(i=0;i<sz;i++)
        {
            if(mp.find(B[i])==mp.end())
            {
                res[i]=q.front();
                q.pop();
            }
            else
            {
                sz1=mp[B[i]].size();
                res[i]=mp[B[i]][sz1-1];
                mp[B[i]].pop_back();
                // res[i]=mp[B[i]][0];
                // mp[B[i]].pop_front();
                if(mp[B[i]].size()==0)
                    mp.erase(B[i]);
            }
        }
        return res;
    }
};
