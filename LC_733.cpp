class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        if((image.size()==0) || (image[sr][sc]==newColor))
            return image;

    int prev=image[sr][sc];
    floodfill(image,sr,sc,newColor,prev);
    return image;
    }
    void floodfill(vector<vector<int>>& image,int x,int y,int newc,int prev)
    {
        if((x<0) || (x>=image.size()) || (y<0) || (y>=image[0].size()))
            return;
        if(image[x][y]!=prev)
            return;
        image[x][y]=newc;
        floodfill(image,x+1,y,newc,prev);
        floodfill(image,x,y+1,newc,prev);
        floodfill(image,x-1,y,newc,prev);
        floodfill(image,x,y-1,newc,prev);
    }
};
