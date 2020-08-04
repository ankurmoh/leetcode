bool myCompare(string a, string b){
    int i = a.find(' ');
    int j = b.find(' ');
    if(!isdigit(a[i + 1]) && !isdigit(b[j + 1]))
        return a.substr(i + 1) < b.substr(j + 1);
    else{
        if(!isdigit(a[i + 1])) return true;
        return false;
    }
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), myCompare);
        return logs;
    }
};
