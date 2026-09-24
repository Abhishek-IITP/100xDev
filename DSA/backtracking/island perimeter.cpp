class Solution {
public:
    int fn(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
            return 1;

        // Water
        if (grid[i][j] == 0) return 1;

        if (grid[i][j]==2){
            return 0;
        } 


        //visited
        grid[i][j] =2;


        int perimeter = 0;

        // Up
        perimeter += fn(grid, i - 1, j);

        // Down
        perimeter += fn(grid, i + 1, j);

        // Right
        perimeter += fn(grid, i, j + 1);

        // Left
        perimeter += fn(grid, i, j - 1);

        return perimeter;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] ==1){
                    return fn(grid,i,j);
                }
            }
        }
        return 0;
    }
};