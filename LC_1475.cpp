class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>s;
        int i,len=prices.size();
        for(i=0;i<len;i++)
        {
            while((!s.empty()) && (prices[s.top()]>=prices[i]))
            {
                prices[s.top()]=prices[s.top()]-prices[i];
                s.pop();
            }
            s.push(i);
        }
      return prices;
    }
};
