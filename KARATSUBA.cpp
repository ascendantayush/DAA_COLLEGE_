#include<bits/stdc++.h>
using namespace std;


long long karatsuba(long long x, long long y){
    if(x < 10 || y < 10){
        return x * y;
    }
    
    int size = 0;
    long long temp =  x > y ? x : y;
    while(temp != 0){
        temp = temp/10;
        size++;
    }
    
    int half_size = size / 2;
    long long power = 1;
    for(int i= 0 ; i < half_size ; i++){
        power *= 10;
    }
    
    long long h1 = x/power;
    long long l1 = x%power;
    
    long long h2 = y/power;
    long long l2 = y%power;
    
    long long z0 = karatsuba(l1,l2);
    long long z1 = karatsuba (l1 + h1 , l2 + h2);
    long long z2 = karatsuba(h1,h2);
    
    
    return z2 * power * power + (z1 - z2 - z0) * power + z0;
}



int main(){
    long long x = 12;
    long long y = 12;
    
    long long ans = karatsuba(x,y);
    cout << ans << endl;
}
