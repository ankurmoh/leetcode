class Solution {
public:
    int maxhist(vector<int>& heights)
    {
        stack<int>s;
        s.push(-1);
        int i,n=heights.size(),top,range,maxarea=0;
        for(i=0;i<n;i++)
        {
            while((s.top()!=-1) && (heights[s.top()]>=heights[i]))
            {
                top = heights[s.top()];
                s.pop();
                range = i-s.top()-1;
                maxarea=max(maxarea,range*top);
            }
            s.push(i);
        }
        while(s.top()!=-1)
        {
            top = heights[s.top()];
            s.pop();
            range = n-s.top()-1;
            maxarea=max(maxarea,range*top);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int i,j,sz1=matrix.size(),sz2,k,width,maxarea=0;
        if(sz1==0)
            return 0;
        sz2=matrix[0].size();
        /*vector<vector<int>>dp(sz1+1,vector<int>(sz2+1,0));
        for(i=0;i<sz1;i++)
        {
            for(j=0;j<sz2;j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(j==0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=1+dp[i][j-1];
                }
                width = dp[i][j];
                for(k=i;k>=0;k--)
                {
                    if(width>dp[k][j])
                        width=dp[k][j];
                    maxarea=max(maxarea,width*(i-k+1));
                }
            }
        }*/
        vector<int>dp(sz2+1,0);
        for(i=0;i<sz1;i++)
        {
            for(j=0;j<sz2;j++)
            {
                if(matrix[i][j]=='1')
                    dp[j]=1+dp[j];
                else
                    dp[j]=0;
            }
            maxarea=max(maxarea,maxhist(dp));
        }
        return maxarea;
    }
};
