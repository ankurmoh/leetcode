class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int i,j,k,sz = prerequisites.size();
        vector<vector<int>>dp(n,vector<int>(n,false));
        //for(i=0;i<n;i++)
          //  dp[i][i]=true;
        for(i=0;i<sz;i++)
            dp[prerequisites[i][0]][prerequisites[i][1]]=true;
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    dp[i][j]=(dp[i][j]||(dp[i][k] && dp[k][j]));
            }
        }
        sz = queries.size();
        vector<bool>res;
        for(i=0;i<sz;i++)
        {
            if(dp[queries[i][0]][queries[i][1]])
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
        /*int i,j,sz = prerequisites.size(),fron,neigh;
        unordered_map<int, unordered_set<int>>graph;
        unordered_map<int, unordered_set<int>>preq;
        vector<int>indegree(n,0);
        vector<bool>res;
        queue<int>q;
        for(i=0;i<sz;i++)
        {
            graph[prerequisites[i][0]].insert(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        for(i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            fron = q.front();
            q.pop();
            for(auto it = graph[fron].begin();it!=graph[fron].end();it++)
            {
                neigh = *it;
                preq[neigh].insert(fron);
                preq[neigh].insert(preq[fron].begin(),preq[fron].end());
                indegree[neigh]--;
                if(indegree[neigh]==0)
                    q.push(neigh);
            }
        }
        sz = queries.size();
        for(i=0;i<sz;i++)
        {
            if(preq[queries[i][1]].count(queries[i][0]))
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;*/
    }
};
