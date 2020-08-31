class Solution {
public:
    int numTrees(int n) {
        
        vector<int>catalan(n+1,1);
        int i,temp,j;
        for(i=2;i<=n;i++)
        {
            temp=0;
            for(j=0;j<i;j++)
            {
                temp=temp + catalan[j]*catalan[i-j-1];
            }
            catalan[i] = temp;
        }
        return catalan[n];

        long long int C=1,i;
        for(i=0;i<n;i++)
            C = C*(2*(2*i + 1))/(i+2);
        return int(C);
    }
};
