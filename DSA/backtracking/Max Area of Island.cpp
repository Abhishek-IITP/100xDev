class Solution {
public:
    int fn(vector<vector<int>>& grid, int i,int j){

        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>= m) return 0;

        // Water or already visited
        if(grid[i][j] == 0)
            return 0;

        grid[i][j] =0;

        int area =1;
        //up
        area+= fn(grid, i-1,j);
        
        //down
        area+= fn(grid, i+1,j);

        //right
        area+= fn(grid, i,j+1);

        //left
        area+= fn(grid, i,j-1);

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        

        int n = grid.size();
        int m = grid[0].size();
        int output=INT_MIN;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){

                output = max(output,fn(grid,i,j));
            }
        }

        return output;
    }
};