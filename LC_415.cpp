class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.length(),len2=num2.length(),a,b,sum,carry;
        int i,len,diff;
        string temp="",temp1="";
        string result="";
        if(len1<len2)
        {
            diff=len2-len1;
            for(i=0;i<diff;i++)
                temp=temp+'0';
            temp=temp+num1;
            len=len2;
            temp1=num2;
        }
        else if(len1>len2)
        {
            diff=len1-len2;
            for(i=0;i<diff;i++)
                temp=temp+'0';
            temp=temp+num2;
            len=len1;
            temp1=num1;
        }
        else if(len1==len2)
        {
            len=len1;
            temp=num1;
            temp1=num2;
        }
        sum=0;
        carry=0;
        char ch;
        for(i=len-1;i>=0;i--)
        {
            a=(int)temp[i]-'0';
            b=(int)temp1[i]-'0';
            sum=a+b+carry;
            if((sum%10)==0)
                result=result+'0';
            else if((sum%10)>0)
            {
            ch=(sum%10) + '0';
            result=result+ch;
            }
            carry=sum/10;
        }
        if(carry>0)
        {
            ch=carry+'0';
            result=result+ch;
        }
        len=result.length();
        string res1="";
        for(i=len-1;i>=0;i--)
        {
            ch=result[i];
            res1=res1+result[i];
        }
        return res1;
    }
};
