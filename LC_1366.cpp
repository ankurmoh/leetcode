class Solution {
public:
    static bool cmp(const pair<char, vector<int>>& a, const pair<char, vector<int>>& b){
        for(int i = 0; i < a.second.size(); i++)
        {
            if(a.second[i] > b.second[i])
                return true;
            if(a.second[i] < b.second[i])
                return false;
        }
        return a.first < b.first;
    }
    string rankTeams(vector<string>& votes) {
        if(votes.size() == 1)
            return votes.back();

        unordered_map<char, vector<int>> mp;
        vector<int> init(votes[0].size(), 0);
        for(int i = 0; i < votes[0].size(); i++)
            mp[votes[0][i]] = init;

        for(int i = 0; i < votes.size(); i++){
            for(int j = 0; j < votes[i].size(); j++){
                mp[votes[i][j]][j]++;
            }
        }

        pair<char, vector<int>> temp;
        vector<pair<char, vector<int>>> helper;
        for(auto it : mp)
        {
            temp = make_pair(it.first, it.second);
            helper.push_back(temp);
        }
        sort(helper.begin(), helper.end(), cmp);
        string ret = "";

        for(auto p : helper)
            ret.push_back(p.first);

        return ret;
    }
};
