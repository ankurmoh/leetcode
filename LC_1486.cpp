class Solution {
public:
    int xorOperation(int n, int start) {
        int i,num,xorval=start;
        for(i=1;i<n;i++)
        {
            num = start+ 2*i;
            xorval=xorval ^ num;
        }
        return xorval;
    }
};
