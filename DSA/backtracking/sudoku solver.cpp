#include <bits/stdc++.h>

using namespace std;
bool canPlace(int row, int col, int val, vector < vector < int >> & board) {

    int n = board.size();
    int m = board[0].size();

    //same row
    for (int j = 0; j < n; j++) {
        if (board[row][j] == val) {
            return false;
        }
    }

    //same col
    for (int i = 0; i < n; i++) {
        if (board[i][col] == val) {
            return false;
        }
    }

    //same box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val) {
                return false;
            }
        }
    }

    return true;

}

void printPath(vector < vector < int >> & board) {
    for (auto & row: board) {
        for (auto & num: row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool fn(int i, int j, vector < vector < int >> & board) {

    //all rows completed and one complete soln found 
    if (i == 9) {
        printPath(board);
        return true;
    }

    // move to the next row
    if (j == 9) {
        return fn(i + 1, 0, board);

    }

    if (board[i][j] != 0) {
        return fn(i, j + 1, board);
    }
    
    for (int val = 1; val <= 9; val++) {
            if (canPlace(i, j, val, board)) {

                //choose
                board[i][j] = val;

                //explore

                if (fn(i, j + 1, board)) {
                    return true; //stop everything
                }
                //backtrack
                board[i][j] = 0;
            }
        }
    
    return false;

}

int main() {

vector < vector < int >> board = {
        {
            5,3,0,0,7,0,0,0,0
        },
        {
            6,0,0,1,9,5,0,0,0
        },
        {
            0,9,8,0,0,0,0,6,0
        },
        {
            8,0,0,0,6,0,0,0,3
        },
        {
            4,0,0,8,0,3,0,0,1
        },
        {
            7,0,0,0,2,0,0,0,6
        },
        {
            0,6,0,0,0,0,2,8,0
        },
        {
            0,0,0,4,1,9,0,0,5
        },
        {
            0,0,0,0,8,0,0,7,9
        }
    };

    fn(0, 0, board);

    return 0;
}