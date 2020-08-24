class Solution {
public:
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int x,int y,vector<vector<int>>& visited,vector<vector<int>>& A,queue<pair<int,int>>& q)
    {
        q.push(make_pair(x,y));
        visited[x][y]=1;
        int i,newx,newy;
        for(i=0;i<4;i++)
        {
            newx = x+dir[i][0];
            newy = y+dir[i][1];
            if((newx<0)||(newx>=A.size())||(newy<0)||(newy>=A[0].size())||(A[newx][newy]==0)||(visited[newx][newy]))
                continue;
            dfs(newx,newy,visited,A,q);
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size(),res=0,i,j,n,flag=0,step,sz,x,y,newx,newy;
        if(m==0)
            return res;
        n=A[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<int,int>>q;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if((visited[i][j]==0) && (A[i][j]))
                {
                    dfs(i,j,visited,A,q);
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        step=0;
        while(!q.empty())
        {
            sz=q.size();
            for(i=0;i<sz;i++)
            {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(j=0;j<4;j++)
            {
                newx=x+dir[j][0];
                newy=y+dir[j][1];
                if((newx>=0) && (newx<m) && (newy>=0) && (newy<n) && (!visited[newx][newy]))
                {
                    if(A[newx][newy]==1)
                        return step;
                    visited[newx][newy]=1;
                    q.push(make_pair(newx,newy));
                }
            }
            }
            step++;
        }
        return step;
    }
};
