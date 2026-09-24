#include <bits/stdc++.h>
using namespace std;

bool canPlace(int row, int col, vector<string>& board, int n) {

    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int k = 0; k < 8; k++) {

        int i = row + dr[k];
        int j = col + dc[k];

        if (i >= 0 && i < n && j >= 0 && j < n) {
            if (board[i][j] == 'K') {
                return false;
            }
        }
    }

    return true;
}
void printPath(vector<string>& board) {
    for (auto& row : board) {
        cout << row << endl;
    }
    cout << endl;
}

void fn(int n,int i,int knights, vector<string>& board){
    if (knights == n){
        printPath(board);
        return;
    }
    
    // Board completely checked
    if (i == n * n) {
        return;
    }
    int r = i / n;
    int c = i % n;

        if(canPlace(r,c,board,n)){
            board[r][c] ='K';
            fn(n,i+1,knights+1, board);
            board[r][c] ='.';
        }
        
        fn(n, i + 1, knights, board);
}

int main() {
	int n;
	cin>>n;
	
	vector<string> board(n, string(n, '.'));
	
	fn(n,0,0,board);
	
 return 0;
}
