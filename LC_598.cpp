class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int i,len=ops.size();
        for(i=0;i<len;i++)
        {
            m=min(m,ops[i][0]);
            n=min(n,ops[i][1]);
        }
        return (m*n);
    }
};
