class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //map<string,int>mp;
        priority_queue<string>pq;
        int i,sz=products.size(),len=searchWord.length(),j;
        vector<vector<string>>res;
        string temp="";
        for(i=0;i<len;i++)
        {
            temp=temp+searchWord[i];
            //mp.clear();
            pq = priority_queue<string>();
            for(j=0;j<sz;j++)
            {
                if(products[j].substr(0,i+1) == temp)
                {
                    //if(mp.size()<3)
                      //  mp[products[j]]=1;
                    if(pq.size()<3)
                        pq.push(products[j]);
                    else if(pq.size()==3)
                    {
                        // auto itr = mp.end();
                        // --itr;
                        // if (itr->first>products[j])
                        // {
                        // mp.erase(itr);
                        // mp[products[j]]=1;
                        // }
                        if(pq.top()>products[j])
                        {
                            pq.pop();
                            pq.push(products[j]);
                        }
                    }
                }
            }
            vector<string>t;
            // for(auto it=mp.begin();it!=mp.end();it++)
            //     t.push_back(it->first);
            while(!pq.empty())
            {
                t.push_back(pq.top());
                pq.pop();
            }
            reverse(t.begin(),t.end());
            res.push_back(t);
        }
        return res;
    }
};
