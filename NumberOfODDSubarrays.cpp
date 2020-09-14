class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       int i,sz=arr.size(),res=0,mod = 1000000007,prevodd=0,preveven=0;
        vector<int>odd(sz,0);
        vector<int>even(sz,0);
        if(arr[0]%2)
            //odd = 1;
            odd[0]=1;
        else
            //even=1;
            even[0]=1;
        // prevodd = odd;
        // preveven = even;
        res = odd[0];
        for(i=1;i<sz;i++)
        {
            if(arr[i]%2==0)
            {
                odd[i]=odd[i-1]%mod;
                even[i]=(1+even[i-1])%mod;
                // odd = prevodd;
                // even = preveven + 1;
            }
            else
            {
                odd[i]=(1+even[i-1])%mod;
                even[i]=odd[i-1]%mod;
                // odd = 1 + preveven;
                // even = prevodd;
            }
            // res = (res + odd)%mod;
            // prevodd = odd;
            // preveven = even;
            res = (res + odd[i])%mod;
        }
        return res;
    }
};
