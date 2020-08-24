class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue< int , vector< int > , greater<int> >pq;
       vector<string>ans;
        int i,j,val;
        unordered_map<string,int>mp;
        for(i=0;i<words.size();i++)
            mp[words[i]]++;

        unordered_map<int, vector<string> >mp1;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push(it->second);
            mp1[it->second].push_back(it->first);
        }
        for(auto it=mp1.begin();it!=mp1.end();it++)
            sort(it->second.begin(),it->second.end());
        while(pq.size()!=k)
        {
            if(mp1[pq.top()].size()>=1)
                mp1[pq.top()].pop_back();
            if(mp1[pq.top()].size()==0)
                mp1.erase(pq.top());
            pq.pop();
        }
        while(!pq.empty())
        {
            val = pq.top();
            pq.pop();
            vector<string>temp = mp1[val];
            ans.insert(ans.begin(),temp.begin(),temp.end());
            mp1.erase(val);
        }
        return ans;
    }
};
