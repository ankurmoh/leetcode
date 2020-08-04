class Solution {
public:
    int numSub(string s) {
        long long int con,i=0,len=s.length(),res=0,j;
        while(i<len)
        {
            if(s[i]=='1')
            {
                con=1;
                j=i+1;
                while((j<len) && (s[j]=='1'))
                {
                    con++;
                    j++;
                }
                res=(res + ((con)*(con+1)/2)%1000000007)%1000000007;
                i=j;
            }
            else
            {
                con=0;
                i++;
            }
        }
        return res;
    }
};
