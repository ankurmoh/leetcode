/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int>important;
        int i,len=employees.size(),ans=0,j,sz,fron,idof;
        if(len==0)
            return 0;
        vector<vector<int>>graph(2000);
        for(i=0;i<len;i++)
        {
            idof=employees[i]->id;
            important[idof]=employees[i]->importance;
            sz=employees[i]->subordinates.size();

            for(j=0;j<sz;j++)
                graph[idof].push_back(employees[i]->subordinates[j]);
        }

        queue<int>q;
        q.push(id);
        unordered_map<int,bool>visited;
        visited[id]=true;

        while(!q.empty())
        {
            fron=q.front();
            q.pop();
            ans+=important[fron];
            sz=graph[fron].size();

            for(i=0;i<sz;i++)
            {
                if(visited.find(graph[fron][i])==visited.end())
                {
                q.push(graph[fron][i]);
                visited[graph[fron][i]]=true;
                }
            }

        }
        return ans;
    }
};
