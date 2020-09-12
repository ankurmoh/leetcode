class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website)
    {
        unordered_map<string, vector<pair<int,string>> >mp;
        vector<string>ans;
        int i,sz=username.size(),j,k,maxsz = 0;
        if(sz==0)
            return ans;
        string res = "",sol;
        for(i=0;i<sz;i++)
            mp[username[i]].push_back(make_pair(timestamp[i],website[i]));
        unordered_map<string,int>freq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<pair<int,string>>temp = it->second;
            sort(temp.begin(),temp.end());
            sz = temp.size();
            unordered_set<string>visited;
            for(i=0;i<sz-2;i++)
            {
                for(j=i+1;j<sz-1;j++)
                {
                    for(k=j+1;k<sz;k++)
                    {
                        sol = temp[i].second+" "+temp[j].second+" "+temp[k].second;
                        if(visited.count(sol) == 0)
                        {
                        if(freq.find(sol) == freq.end())
                            freq[sol] = 1;
                        else
                            freq[sol]++;
                        visited.insert(sol);
                        }
                        maxsz = max(maxsz,freq[sol]);
                    }
                }
            }
        }
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            if(it->second==maxsz)
            {
                if((res == "") || (res>it->first))
                    res = it->first;
            }
        }
        sol = "";
        sz = res.length();
        for(i=0;i<sz;i++)
        {
            if(res[i]==' ')
            {
                ans.push_back(sol);
                sol="";
            }
            else
                sol=sol+res[i];
        }
        if(sol!="")
            ans.push_back(sol);
        return ans;
    }
};
