class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        string temp="";
        pair<int,char>first,second;
        if(a)
            pq.push(make_pair(a,'a'));
        if(b)
            pq.push(make_pair(b,'b'));
        if(c)
            pq.push(make_pair(c,'c'));
        if(pq.empty())
            return temp;
        while(pq.size()>1)
        {
            first = pq.top();
            pq.pop();
            second=pq.top();
            pq.pop();
            if(first.first>=2)
            {
                temp=temp+string(2,first.second);
                first.first -= 2;
            }
            else if(first.first==1)
            {
                temp=temp+first.second;
                first.first -= 1;
            }
            if((second.first>=2) && (second.first>=first.first))
            {
                temp=temp+string(2,second.second);
                second.first -= 2;
            }
            else
            {
                temp=temp+second.second;
                second.first -= 1;
            }
            if(first.first>0)
                pq.push(first);
            if(second.first>0)
                pq.push(second);
        }
        if(pq.empty())
            return temp;
        first=pq.top();
        pq.pop();
        if(first.first>=2)
           temp=temp+string(2,first.second);
        else
            temp=temp+first.second;
        return temp;
    }
};
