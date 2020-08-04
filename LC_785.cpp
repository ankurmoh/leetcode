class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0)
            return true;
        unordered_map<int,int>color;
        int fron,sz,i,len,flag=0;
        sz=graph.size();
        for(i=0;i<sz;i++)
        {
         if((graph[i].size()>0) && (color.find(i)==color.end()))
         {
          queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty())
        {
            fron=q.front();
            q.pop();
            len=graph[fron].size();
            for(i=0;i<len;i++)
            {
                if(color.find(graph[fron][i])==color.end())
                {
                    q.push(graph[fron][i]);
                    color[graph[fron][i]]=1-color[fron];
                }
                else if(color.find(graph[fron][i])!=color.end())
                {
                    if(color[graph[fron][i]]==color[fron])
                        return false;
                }
            }
        }
        }
        }
        return true;
    }
};
