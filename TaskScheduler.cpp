class Solution {
public:
  struct comp
  {
    bool operator()(const pair<int,char>& c1,const pair<int,char>& c2)
    {
      if(c1.first!=c2.first)
      {
        return c1.first<c2.first;
      }
      return c1.second>c2.second;
    }
  };
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,comp>pq;
        int i,sz=tasks.size(),con=0,k;
        unordered_map<char,int>mp;
        pair<int,char>fron;
        for(i=0;i<sz;i++)
            mp[tasks[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
            pq.push(make_pair(it->second,it->first));
        vector<pair<int,char>>cache;
        while(!pq.empty())
        {
            k=n+1;
            while((k>0) && (!pq.empty()))
            {
                fron = pq.top();
                pq.pop();
                con++;
                k--;
                fron.first = fron.first - 1;
                if(fron.first>0)
                    cache.push_back(fron);
            }
            for(i=0;i<cache.size();i++)
                pq.push(v[i]);
            cache.clear();
            if(pq.empty())
                break;
            con=con + k;
        }
        return con;
    }
};
