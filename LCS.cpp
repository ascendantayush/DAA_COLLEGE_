#include <bits/stdc++.h>
using namespace std;

int m,n;
int t[1001][1001];

int lcs(string& s1, string& s2,int i, int j){
    if(i >= m  || j >= n){
        return 0;
    } 
    
    if(t[i][j] != -1){
        return t[i][j];
    }
    
    if(s1[i] == s2[j]){
        return t[i][j] = 1 + lcs(s1,s2,i+1,j+1);
    }
    
    else{
        return t[i][j] = max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    }
}


string find(string& s1,string& s2){
    string ans= "";
    int i = m - 1 ;
    int j = n - 1 ;
    
    while(i >= 0 && j>=0){
        if(s1[i] == s2[j]){
            ans = s1[i] + ans;
            i--;
            j--;
        }
        
        else if(t[i-1][j] > t[i][j-1]) i--;
        else j--;
        
    }
    
    return ans;
}




int main(){
    string a,b;
    cout << "start" << endl;
    
    getline(cin,a);
    getline(cin,b);
    
    m = a.length();
    n = b.length();
    
    memset(t,-1,sizeof(t));
    
    
    int lcs_ans= lcs(a,b,0,0);
    string ans= find(a,b);
    
    cout << "maxium lenght" << lcs_ans << endl;
    cout << ans ;
    
    return 0;
}
