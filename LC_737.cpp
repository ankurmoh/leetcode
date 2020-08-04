class Solution {
public:
    // bool dfs(unordered_map<string,set<string>>& graph,string src,string dest,unordered_set<string>& visited)
    // {
    //     if(src==dest)
    //         return true;
    //     visited.insert(src);
    //     for(auto it = graph[src].begin();it!=graph[src].end();it++)
    //     {
    //         if(!visited.count(*it))
    //         {
    //             if(dfs(graph,*it,dest,visited))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }

    bool bfs(unordered_map<string,unordered_set<string>>& graph,string src,string dest,unordered_set<string>& visited)
    {
        if(src == dest)
            return true;
        visited.insert(src);
        queue<string>q;
        q.push(src);
        string fron;
        while(!q.empty())
        {
            fron = q.front();
            q.pop();
            if(fron == dest)
                return true;
        for(auto it = graph[fron].begin();it!=graph[fron].end();it++)
        {
            if(!visited.count(*it))
            {
                q.push(*it);
                visited.insert(*it);
            }
        }
        }
        return false;
    }

    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size()!=words2.size())
            return false;
        unordered_map< string, unordered_set<string> > graph;
        unordered_set<string> visited;
        int i,sz=pairs.size();
        for(i=0;i<sz;i++)
        {
            graph[pairs[i][0]].insert(pairs[i][1]);
            graph[pairs[i][1]].insert(pairs[i][0]);
        }
        sz=words1.size();
        for(i=0;i<sz;i++)
        {
            if(words1[i]==words2[i])
                continue;
            if(graph[words1[i]].count(words2[i]))
                continue;
            if(!bfs(graph,words1[i],words2[i],visited))
                return false;
            visited.clear();
        }
        return true;
    }
};
