class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int i,len=updates.size();
        vector<int>res(length,0);
        for(i=0;i<len;i++)
        {
            res[updates[i][0]] += updates[i][2];
            if(updates[i][1]+1<length)
                res[updates[i][1] + 1] -= updates[i][2];
        }
        for(i=1;i<length;i++)
            res[i] += res[i-1];
        return res;
    }
};
