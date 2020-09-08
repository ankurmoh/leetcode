class Solution {
public:
    string rearrangeString(string s, int k) {
        priority_queue<pair<int,char>>pq;
        int i,len=s.length(),con;
        if(k==0)
            return s;
        unordered_map<char,int>mp;
        for(i=0;i<len;i++)
            mp[s[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
            pq.push(make_pair(it->second,it->first));
        string res = "";
        pair<int,char>fron;
        while(!pq.empty())
        {
            con = min(k,len);
            vector<pair<int,char>>cache;
            for(i=0;i<con;i++)
            {
                if(pq.empty())
                    return "";
                fron = pq.top();
                pq.pop();
                res= res + fron.second;
                fron.first = fron.first-1;
                if(fron.first>0)
                    cache.push_back(fron);
                len--;
            }
            for(i=0;i<cache.size();i++)
                pq.push(cache[i]);
        }
        return res;
    }
};
