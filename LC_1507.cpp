class Solution {
public:
    string reformatDate(string date) {
        int day,month_1,year,i,len=date.length();
        if(date[1]=='s')
            day=1;
        if(date[1]=='n')
            day=2;
        if(date[1]=='t')
            day=3;
        day = stoi(date.substr(0,2));
        unordered_map<string,int>month;
        month["Jan"]=1;
        month["Feb"]=2;
        month["Mar"]=3;
        month["Apr"]=4;
        month["May"]=5;
        month["Jun"]=6;
        month["Jul"]=7;
        month["Aug"]=8;
        month["Sep"]=9;
        month["Oct"]=10;
        month["Nov"]=11;
        month["Dec"]=12;
        for(i=0;i<len;i++)
        {
            if((date[i]==' ') && (date[i+1]>='A') && (date[i+1]<='Z'))
            {
                month_1 = month[date.substr(i+1,3)];
            }
            else if(date[i]==' ')
                year=stoi(date.substr(i+1,4));
        }
        string day1=to_string(day),month_2=to_string(month_1);
        if(day1.length()==1)
            day1="0"+day1;
        if(month_2.length()==1)
            month_2="0"+month_2;
        string res = to_string(year) + "-" + month_2+"-"+day1;
        cout<<day<<" "<<month_1<<" "<<year;
        return res;
    }
};
