#include <iostream>
#include <climits>
using namespace std;

struct sub_array{
    int sum;
    int start;
    int end;
};


sub_array crossum(int arr[],int l , int m , int r){
    int left_sum = INT_MIN;
    int left_index = m;
    int temp_sum = 0;
    
    for(int i = m ; i>= 0; i--){
        temp_sum += arr[i];
        if(temp_sum > left_sum){
            left_sum = temp_sum;
            left_index = i;
        }
    }
    
    
    int right_sum = INT_MIN;
    int right_index = m+1;
    temp_sum = 0;
    
    for(int i = m+1; i <= r ; i++){
        temp_sum += arr[i];
        if(temp_sum > right_sum){
            right_sum = temp_sum;
            right_index = i;
        }
    }
    
    sub_array result;
    result.sum = left_sum + right_sum;
    result.start = left_index;
    result.end = right_index;
    
    return result;
}

sub_array maxi(sub_array l,sub_array r,sub_array c){
    if(l.sum > r.sum && l.sum > c.sum) return l;
    else if(r.sum > l.sum && r.sum > c.sum) return r;
    else  return c;
}



sub_array maximumSubArray(int arr[] , int l , int r){
    if( l == r){
        sub_array ans;
        ans.sum = arr[l];
        ans.start = l;
        ans.end = l;
    
        return ans;
    }
    
    int mid = (l+r)/2 ;
    sub_array left = maximumSubArray(arr,l,mid);
    sub_array right = maximumSubArray(arr,mid+1,r);
    sub_array center = crossum(arr,l,mid,r);
    
    //find the maximum
    
    sub_array answer = maxi(left,right,center);
    
    return answer;
}


int main(){
    int arr[7] = {-2,-3,2,4,6,-1,7};
    sub_array res = maximumSubArray(arr,0,6);
    cout << res.sum << endl;
    for(int i = res.start ; i<= res.end ; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    return 0;
}
