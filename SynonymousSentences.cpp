class Solution {
public:
    vector<string> extract(string s)
    {
        int i,len=s.length();
        string temp = "";
        vector<string>res;
        for(i=0;i<len;i++)
        {
            if(s[i]!=' ')
                temp=temp+s[i];
            else
            {
                res.push_back(temp);
                temp="";
            }
        }
        if(temp!="")
            res.push_back(temp);
        return res;
    }
    string make_string(vector<string>& s)
    {
        int i,sz=s.size();
        string temp = "";
        for(i=0;i<=sz-2;i++)
            temp=temp+s[i]+" ";
        temp=temp+s[sz-1];
        return temp;
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string,vector<string>>graph;
        int i,sz=synonyms.size(),j,sz1;
        for(i=0;i<sz;i++)
        {
            graph[synonyms[i][0]].push_back(synonyms[i][1]);
            graph[synonyms[i][1]].push_back(synonyms[i][0]);
        }
        queue<string>q;
        unordered_set<string>s;
        q.push(text);
        s.insert(text);
        vector<string>res;
        string fron,temp,revert;
        while(!q.empty())
        {
            fron = q.front();
            q.pop();
            res.push_back(fron);
            vector<string>words = extract(fron);
            sz = words.size();
            for(i=0;i<sz;i++)
            {
                if(graph.find(words[i])==graph.end())
                    continue;
                sz1 = graph[words[i]].size();
                for(j=0;j<sz1;j++)
                {
                    revert = words[i];
                    words[i]=graph[words[i]][j];
                    temp = make_string(words);
                    if (s.count(temp) == 0)
                    {
                        q.push(temp);
                        s.insert(temp);
                    }
                    words[i]=revert;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
