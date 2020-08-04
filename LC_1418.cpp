class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<pair<int,string> ,int>mp;
        set<string>items;
        set<int>table;
        int i,sz=orders.size(),j;
        for(i=0;i<sz;i++)
        {
            table.insert(stoi(orders[i][1]));
            items.insert(orders[i][2]);
            mp[make_pair(stoi(orders[i][1]), orders[i][2])]++;
        }
        vector<string>temp;
        temp.push_back("Table");
        temp.insert( temp.end(), items.begin(),items.end() );
        vector<vector<string>>res;
        res.push_back(temp);
        vector<string>temp1 = temp;
        temp.clear();
        while(!table.empty())
        {
            auto tab = table.begin();
            temp.push_back(to_string(*tab));
            for(j=1;j<temp1.size();j++)
            {

                pair<int,string>pp = make_pair(*tab,temp1[j]);
                if(mp.find(pp)==mp.end())
                    temp.push_back("0");
                else
                    temp.push_back(to_string(mp[pp]));
            }

            res.push_back(temp);
            table.erase(table.begin());
            temp.clear();
        }
        return res;
    }
};
