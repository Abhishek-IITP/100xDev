#include <bits/stdc++.h>
using namespace std;

bool canPlace(int row, int col, vector<string>& board, int n){
    
     // Check same column
    
    int i=row -1;
    
    while(i>=0){
        if (board[i][col] == 'Q'){
            return false;
        }
        i--;
    } 
    
    
       // Check upper-left diagonal
    i=row -1;
    int j =col -1;
   while(i>=0 && j>=0){
        if (board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }

    // Check upper-right diagonal
    i=row -1;
     j =col -1;
   while(i>=0 && j>=0){
        if (board[i][j] == 'Q'){
            return false;
        }
        i--;
        j++;
    }

    return true;
    
}

void printPath(vector<string>& board) {
    for (auto& row : board) {
        cout << row << endl;
    }
    cout << endl;
}

void fn(int n,int i, vector<string>& board){
    if (i == n){
        printPath(board);
        return;
    }
    
    for(int j =0;j<n;j++){
        if(canPlace(i,j,board,n)){
            board[i][j] ='Q';
            fn(n,i+1, board);
            board[i][j] ='.';
        }
    }
}

int main() {
	int n;
	cin>>n;
	
	vector<string> board(n, string(n, '.'));
	
	fn(n,0,board);
	
 return 0;
}
