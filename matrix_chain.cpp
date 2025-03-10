#include  <bits/stdc++.h>
using namespace std;

#define N 108
int dp[N][N];
int bracket[N][N];

int f(int arr[],int i,int j){
    if( i == j) return 0;
    
    if( dp[i][j] != -1){
        return dp[i][j];
    }
    
    else{
        int mini = INT_MAX;int best_k = -1;
        for(int k = i ; k <= j-1 ; k++){
            int ans = f(arr,i,k) + f(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            if(ans < mini){
                mini = ans;
                best_k = k;
            }
        }
        
        bracket[i][j] = best_k;
        return dp[i][j] = mini;
    }
}

void printOptimalParens(int i, int j) {
    if (i == j) {
        cout << "M" << i;
        return;
    }
    cout << "(";
    printOptimalParens(i, bracket[i][j]);      // Left part
    printOptimalParens(bracket[i][j] + 1, j);  // Right part
    cout << ")";
}


int main(){
    int arr[5]= {1,2,3,4,3};
    memset(dp,-1,sizeof(dp));
    int ans = f(arr,1,4);
    cout << ans << endl;
    
    printOptimalParens(1,4);
}
