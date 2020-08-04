class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
        vector<int>indegree(numCourses,0);
        vector<vector<int>>graph(numCourses);
        int i,sz=prerequisites.size(),fron,len,con=0;
        for(i=0;i<sz;i++)
        {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            indegree[to]++;
            graph[from].push_back(to);
        }
        queue<int>q;
        for(i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            fron=q.front();
            q.pop();
            con++;
            res.push_back(fron);
            len=graph[fron].size();
            for(i=0;i<len;i++)
            {
                indegree[graph[fron][i]]--;

                if(indegree[graph[fron][i]]==0)
                    q.push(graph[fron][i]);
            }
        }
        if(con==numCourses)
            return res;
        return vector<int>();
    }
};
