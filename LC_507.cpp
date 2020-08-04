class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==0)
            return false;
        int temp=num,i=1,sum=0;
        for(i=1;i<=num/2;i++)
        {
            if(num%i==0)
                sum=sum+i;
        }
        return (sum==num);
    }
};
