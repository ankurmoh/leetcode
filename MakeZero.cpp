class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0)
            return;
        int m=matrix[0].size(),i,j,row=0,col=0;
        for(i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
                col=1;
        }
        for(i=0;i<m;i++)
        {
            if(matrix[0][i]==0)
                row=1;
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if((matrix[i][0]==0)||(matrix[0][j]==0))
                    matrix[i][j]=0;
            }
        }
        if(col==1)
        {
            for(i=0;i<n;i++)
                matrix[i][0]=0;
        }
        if(row==1)
        {
            for(i=0;i<m;i++)
                matrix[0][i]=0;
        }
    }
};
