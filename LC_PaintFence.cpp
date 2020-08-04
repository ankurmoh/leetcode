class Solution {
public:
    int numWays(int n, int k) {
        int same,diff,temp,i;
        if(n==0)
            return 0;
        if(n==1)
            return k;
        same=k;
        diff=k*(k-1);
        for(i=2;i<n;i++)
        {
            temp=diff;
            diff = (same + diff)*(k-1);
            same = temp;
        }
        return (same + diff);
    }
};
