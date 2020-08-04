class Solution {
public:
    int titleToNumber(string s) {
        int i,len=s.length(),ans=0,current,previous,fact=0;

        for(i=len-1;i>=0;i--)
        {
            ans=ans+ (pow(26,fact) * (s[i]-'A' + 1));
            fact++;
        }
        return int(ans);
    }
};
