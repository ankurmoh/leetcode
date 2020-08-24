//check if (a,b) exisits such that a^2 + b^2  = c

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=1;
        double d;
        if(c==0)
            return true;
        for(i=1;i<=c/i;i++)
        {
            d=sqrt(c - i*i);
            if(d == (int)d)
                return true;
        }
        return false;
    }
};

//pow(x,n)

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        else if(n==1)
            return x;
        double res = myPow(x,n/2);
        if(n%2==0)
            return res*res;
        else
        {
            if(n>0)
                return (x*res*res);
            else
                return ((res*res)/x);
        }
        return x;
    }
};

//valid square
class Solution {
public:
    bool isPerfectSquare(int num) {
       if(num<2)
           return true;
        long long int left=2,right=num/2,mid;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            if(mid*mid == num)
                return true;
            else if(mid*mid > num)
                right=mid-1;
            else
                left=mid+1;
        }
        return false;
    }
};

//int sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        long long int left,right,pivot;
        if(x==0)
            return x;
        if(x<=3)
            return 1;
        left=2;
        right=x/2;
        while(left<=right)
        {
            pivot = left + (right-left)/2 ;
            if((pivot*pivot)==x)
                return pivot;
            else if((pivot*pivot)<x)
                left=pivot+1;
            else if((pivot*pivot)>x)
                right=pivot-1;
        }
        return int(right);
    }
};
