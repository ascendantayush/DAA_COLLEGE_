#include <iostream>
using namespace std;

long long karatsuba(long long x,long long y){
    if(x < 10 || y < 10){
        return x*y;
    }
    
    int size = 0;
    int temp = x > y ? x : y;
    while(temp >0){
        temp = temp/10;
        size++;
    }
    
    int half_size = size / 2;
    long long power = 1;
    for(int i= 0 ; i< half_size ; i++){
        power *= 10;
    }
    
    long long h1 = x/power;
    long long l1= x%power;
    
    long long h2 = y/power;
    long long l2 = y%power;
    
    long long s1= karatsuba(h1,h2);
    long long s2 = karatsuba(l1,l2);
    long long s3 = karatsuba(h1+l1,h2+l2);
    
    return s1*power*power + (s3-s2-s1)*power + s2;
}


int main(){
    long long a = 112345;
    long long b = 124521;
    
    long long ans = karatsuba(a,b);
    cout << ans << endl;
    
}
