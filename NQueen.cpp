#include <iostream>
using namespace std;

#define N 8
int board[N][N] = {0};



bool safe(int board[N][N],int row,int col){
    
    for(int i = 0;i < col ; i++){
        if(board[row][i] == 1){
            return false;
        }
    }
    
    
    for(int i = row, j =col ; i >= 0 && j>= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    
    for(int i = row, j = col; i < N , j>= 0 ;i++,j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    
    return true;
    
}
bool solve(int board[N][N],int col){
    if(col >= N){
        return true;
    }
    
    for(int i = 0 ; i< N ; i++){
        if(safe(board,i,col)){
            board[i][col]  = 1;
            
            if(solve(board,col+1)){
                return true;
            }
            
            board[i][col] = 0;
        }
    }
    
    return false;
}


int main(){
    solve(board,0);
    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j< N ; j++){
            cout << board[i][j] << " ";
        }
        
        cout << endl;
    }
}
