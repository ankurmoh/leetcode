class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,len=prices.size(),buy,sell=INT_MIN,currentprofit,maxprofit=INT_MIN;
        if(len<=1)
            return 0;
        buy=prices[0];
        for(i=1;i<len;i++)
        {
            sell=prices[i];
            currentprofit=sell-buy;
            maxprofit=max(maxprofit,currentprofit);
            buy=min(buy,prices[i]);
        }

        return maxprofit<0? 0:maxprofit;
    }
};
