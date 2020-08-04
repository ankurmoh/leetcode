class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int i,j,rowsz=matrix.size(),colsz=matrix[0].size(),minrow,maxcol;
        vector<int>res;
        unordered_map<int,int>mp;
        for(i=0;i<rowsz;i++)
        {
            minrow=INT_MAX;
            for(j=0;j<colsz;j++)
            {
                if(matrix[i][j]<minrow)
                    minrow=matrix[i][j];
            }
            mp[minrow]=1;
        }
        for(j=0;j<colsz;j++)
        {
            maxcol=0;
            for(i=0;i<rowsz;i++)
            {
                if(matrix[i][j]>maxcol)
                    maxcol=matrix[i][j];
            }
            if(mp.find(maxcol)!=mp.end())
                res.push_back(maxcol);
        }
        return res;
    }
};
