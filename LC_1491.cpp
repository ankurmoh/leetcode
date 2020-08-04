class Solution {
public:
    double average(vector<int>& salary) {
        int i,len=salary.size(),max1=INT_MIN,min1=INT_MAX,sum=0;
        for(i=0;i<len;i++)
        {
            if(salary[i]>max1)
                max1=salary[i];
            if(salary[i]<min1)
                min1=salary[i];
            sum=sum+salary[i];
        }
        sum=sum - (max1+min1);
        double res= (sum * 1.0)/(len-2);
        return res;
    }
};
