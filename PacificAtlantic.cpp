class Solution {
public:
    vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, queue<pair<int,int>>& q)
    {
        int x,y,curx,cury,i;
        while(!q.empty())
        {
            curx=q.front().first;
            cury=q.front().second;
            q.pop();
            for(i=0;i<4;i++)
            {
                x=curx+dir[i][0];
                y=cury+dir[i][1];
                if((x<0)||(x>=matrix.size())||(y<0)||(y>=matrix[0].size())||(visited[x][y]==1)||(matrix[x][y] < matrix[curx][cury]))
                    continue;
                q.push(make_pair(x,y));
                visited[x][y]=1;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int i,j,sz=matrix.size(),sz1;
        vector<vector<int>>res;
        vector<int>temp;
        if(sz==0)
            return res;
        sz1=matrix[0].size();
        if(sz1==0)
            return res;
        vector<vector<int>>pacific(sz,vector<int>(sz1,0));
        vector<vector<int>>atlantic(sz,vector<int>(sz1,0));
        queue<pair<int,int>>p;
        queue<pair<int,int>>a;
        for(i=0;i<sz;i++)
        {
            pacific[i][0]=1;
            atlantic[i][sz1-1]=1;
            p.push(make_pair(i,0));
            a.push(make_pair(i,sz1-1));
        }
        for(i=0;i<sz1;i++)
        {
            pacific[0][i]=1;
            atlantic[sz-1][i]=1;
            p.push(make_pair(0,i));
            a.push(make_pair(sz-1,i));
        }
        bfs(matrix,pacific,p);
        bfs(matrix,atlantic,a);
        for(i=0;i<sz;i++)
        {
            for(j=0;j<sz1;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    temp = {i,j};
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
