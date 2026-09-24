class Solution {
public:

    void solve(int i,int j, int oldColor, int newColor, vector<vector<int>>& image){

        int n = image.size();

        int m = image[0].size();


        if(i < 0 || i >= n || j < 0 || j >= m)
            return;
        
        if(image[i][j] != oldColor)
            return;

        image[i][j] = newColor;

        //up
        solve( i - 1, j, oldColor, newColor,image);
        
        //down
        solve( i + 1, j, oldColor, newColor,image);
        //right
        solve( i , j+1, oldColor, newColor,image);
        //left
        solve( i , j-1, oldColor, newColor,image);



    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;
        
        solve( sr, sc, oldColor, color,image);

        return image;
    }
};