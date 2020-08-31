class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int,char>>pq;
        int i,len=S.length();
        unordered_map<char,int>mp;
        for(i=0;i<len;i++)
            mp[S[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second> (len+1)/2)
                return "";
            pq.push(make_pair(it->second,it->first));
        }
        pair<int,char>fron,sec;
        string temp="";
        while(pq.size()>1)
        {
            fron=pq.top();
            pq.pop();
            sec=pq.top();
            pq.pop();
            temp=temp+fron.second + sec.second;
            fron.first--;
            sec.first--;
            if(fron.first>0)
                pq.push(fron);
            if(sec.first>0)
                pq.push(sec);
        }
        if(pq.empty())
            return temp;
        fron=pq.top();
        pq.pop();
        temp=temp+fron.second;
        return temp;
    }
};
