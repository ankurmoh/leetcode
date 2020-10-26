std::string decodeString(std::string s) {
stack<int>count;
stack<string>res;
string temp="",temp1="",temp2,current,finalans="";
int i,len=s.length(),j,repeat,k;
for(i=0;i<len;)
{
    if((s[i]>='0') && (s[i]<='9'))
    {
        j=i+1;
        temp1=string(1,s[i]);
        while((j<len) && (s[j]>='0') && (s[j]<='9'))
        {
            temp1=temp1 + s[j];
            j++;
        }
        count.push(stoi(temp1));
        temp1="";
        i=j;
    }
    else if((s[i]>='a')&&(s[i]<='z'))
    {
        temp=temp+s[i];
        i++;
    }
    else if(s[i]=='[')
    {
        res.push(temp);
        temp="";
        i++;
    }
    else
    {
        repeat = count.top();
        count.pop();
        temp2 = res.top();
        res.pop();
        for(k=0;k<repeat;k++)
        {
            temp2=temp2 + temp;
        }
        temp=temp2;
        i++;
    }
}
return temp;
}
