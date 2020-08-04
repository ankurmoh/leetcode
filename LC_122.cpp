class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int i=0,sz=prices.size(),peak,valley,ans=0;
        if(sz==0)
            return 0;
       while(i<sz-1)
       {
           while((i<sz-1) && (prices[i]>=prices[i+1]))
               i++;
           valley=prices[i];

           if(i+1<sz)
             peak=prices[i+1];

           else if(i+1>=sz)
               break;

           ans=ans+(peak-valley);

               i=i+1;

           //cout<<ans;
       }
        /*for(i=1;i<sz;i++)
        {
            if(prices[i]-prices[i-1]>=0)
                ans += prices[i]-prices[i-1];
        }*/
        return ans;
    }
};
