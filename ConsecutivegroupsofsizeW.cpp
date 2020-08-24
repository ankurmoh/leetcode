class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int i,sz=hand.size(),con=0,fron;
        if(sz%W!=0)
            return false;
        for(i=0;i<sz;i++)
            pq.push(hand[i]);
        vector<int>straight;
        while(!pq.empty())
        {
            vector<int>temp;
            vector<int>dump;
            while(!pq.empty() && temp.size()<W)
            {
                fron = pq.top();
                pq.pop();
                if((temp.size()==0) || (fron == temp.back() + 1))
                    temp.push_back(fron);
                else
                    dump.push_back(fron);
            }
            for(i=0;i<temp.size();i++)
                straight.push_back(temp[i]);
            if(temp.size()<W)
                return false;
            else
            {
                for(i=0;i<dump.size();i++)
                    pq.push(dump[i]);
            }
        }
        for(i=0;i<straight.size();i++)
            cout<<straight[i]<<" ";
        return true;
    }
};


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
     int i,j,sz=nums.size(),fron;
        if(sz%k!=0)
            return false;
        map<int,int>mp;
        for(i=0;i<sz;i++)
            mp[nums[i]]++;
        while(!mp.empty())
        {
            auto it= mp.begin();
            fron = it->first;
            for(i=fron;i<fron+k;i++)
            {
                if(mp.find(i)==mp.end())
                    return false;
                else
                {
                    mp[i]--;
                    if(mp[i]==0)
                        mp.erase(i);
                }
            }
        }
        return true;
    }
};
