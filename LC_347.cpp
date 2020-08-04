class Solution {
public:
    struct Comp {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const
        {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return true;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto& w : nums)
            ++cnt[w];

        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> Q;
        for (auto it : cnt)
            Q.emplace(it.second, it.first);

        vector<int> res;
        while (!Q.empty() && k>0)
        {
            res.push_back(Q.top().second);
            Q.pop();
            k--;
        }

        return res;
    }
};
