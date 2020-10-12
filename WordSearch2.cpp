class Solution {
public:
    struct node
    {
        char c;
        int ends;
        string word;
        node *child[26];
    };
    struct node *getnode(char c)
    {
        node *newnode = new node;
        newnode->c=c;
        newnode->ends=0;
        newnode->word="";
        for(int i=0;i<26;i++)
            newnode->child[i]=NULL;
        return newnode;
    }
    node *root = getnode('/');
    void insert(string s)
    {
        node *current = root;
        int i=0,index;
        while(s[i])
        {
            index = s[i]-'a';
            if(current->child[index]==NULL)
            {
                current->child[index] = getnode(s[i]);
            }
            current=current->child[index];
            i++;
        }
        current->word=s;
        current->ends += 1;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
     int rows = board.size(),cols = board[0].size(),i,j,sz=words.size(),k;
        for(i=0;i<sz;i++)
            insert(words[i]);
        vector<string>res;
        for(i=0;i<rows;i++)
        {
            for(j=0;j<cols;j++)
            {
                solve(i,j,board,res,root);
            }
        }
        return res;
    }
    void solve(int i,int j,vector<vector<char>>& board,vector<string>& res,node* current)
    {
        int index = board[i][j]-'a';
        if((board[i][j]=='*') || (current->child[index]==NULL))
            return;
        current = current->child[index];
        if(current->ends>0)
        {
            res.push_back(current->word);
            current->ends -= 1;
        }
        char ch = board[i][j];
        board[i][j]='*';
        if(i>0)
            solve(i-1,j,board,res,current);
        if(j>0)
            solve(i,j-1,board,res,current);
        if(i<board.size()-1)
            solve(i+1,j,board,res,current);
        if(j<board[0].size()-1)
            solve(i,j+1,board,res,current);
        board[i][j]=ch;
    }
};
