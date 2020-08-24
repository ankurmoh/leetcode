class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i,j,sz1=triangle.size(),sz2;
        if(sz1==0)
            return 0;
        vector<vector<int>>dp(sz1+1,vector<int>(sz1+1,0));
        for(i=0;i<triangle[sz1-1].size();i++)
            dp[sz1-1][i]=triangle[sz1-1][i];
        for(i=sz1-2;i>=0;i--)
        {
            for(j=0;j<triangle[i].size();j++)
            {
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int i,j,sz1=triangle.size(),sz2;
        if(sz1==0)
            return 0;
        vector<int>dp(triangle.back());

        for(i=sz1-2;i>=0;i--)
        {
            for(j=0;j<triangle[i].size();j++)
            {
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
    int i,j,sz=triangle.size(),res;
    for(i=sz-2;i>=0;i++)
    {
    for(j=0;j<triangle[i].size();j++)
    {
    res = triangle[i][j] + min(triangle[i+1][j],triangle[i+1][j+1]);
    triangle[i][j]=res;
    }
    }
    return triangle[0][0];
    }
};
