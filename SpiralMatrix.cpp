class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int>res;
        if((matrix.size()==0) || (matrix[0].size()==0))
            return res;

        int i,j,rowbegin=0,rowend=matrix.size()-1,colbegin=0,colend=matrix[0].size()-1;
        while((rowbegin<=rowend) && (colbegin<=colend))
        {
            for(j=colbegin;j<=colend;j++)
                res.push_back(matrix[rowbegin][j]);
            rowbegin++;
            for(i=rowbegin;i<=rowend;i++)
                res.push_back(matrix[i][colend]);
            colend--;
            if(rowend>=rowbegin)
            {
            for(j=colend;j>=colbegin;j--)
                res.push_back(matrix[rowend][j]);
            }
            rowend--;
            if(colend>=colbegin)
            {
            for(i=rowend;i>=rowbegin;i--)
                res.push_back(matrix[i][colbegin]);
            }
            colbegin++;

        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0)
            return vector<vector<int>>();
        int no=1,rowb=0,rowe=n-1,colb=0,cole=n-1,i,j;
        vector<vector<int>>grid(n,vector<int>(n,0));
        while((rowb<=rowe) && (colb<=cole))
        {
            for(j=colb;j<=cole;j++)
            {
                grid[rowb][j]=no;
                no++;
            }
            rowb++;
            for(i=rowb;i<=rowe;i++)
            {
                grid[i][cole]=no;
                no++;
            }
            cole--;
            for(j=cole;j>=colb;j--)
            {
                grid[rowe][j]=no;
                no++;
            }
            rowe--;
            for(i=rowe;i>=rowb;i--)
            {
                grid[i][colb]=no;
                no++;
            }
            colb++;
        }
        return grid;
    }
};
