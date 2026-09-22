#include <bits/stdc++.h>

using namespace std;

void printPath(const vector < string > & path) {
    for (auto& num: path) {
        cout << num << " ";
    }
    cout << endl;
}

void fn(int i, int j, int n, int m, vector<vector<int>>& grid
,vector < string > & path) {

    //outside the grid
    if (i >= n || j >= m) return;
    
    //blocked cell 
    if (grid[i][j] == 1)
        return;
    
    if (i == n - 1 && j == m - 1) {
        printPath(path);
        return;
    }

    //right
    path.push_back("r");
    fn(i, j + 1, n, m, grid,path);
    path.pop_back();

    //down
    path.push_back("d");
    fn(i + 1, j, n, m,grid, path);
    path.pop_back();
}

int main() {

    int n, m;

    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector < string > path;

    fn(0, 0, n, m,grid, path);


}