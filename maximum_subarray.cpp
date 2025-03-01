#include <bits/stdc++.h>
using namespace std;

struct SA{
    int sum;
    int start;
    int end;
};


SA mid_sub_array(int arr[] , int low, int mid , int high){
    int leftsum = INT_MIN;
    int sum = 0;
    int left_index = mid;
    
    for(int i = mid ; i >= low ; i--){
        sum += arr[i];
        if(sum > leftsum){
            leftsum =sum;
            left_index = i;
        }
    }
    
    
    sum = 0;
    int right_index = mid + 1;
    int rightsum = INT_MIN;
    
    for(int i = mid + 1; i <= high ; i++){
        sum += arr[i];
        if(sum > rightsum){
            rightsum = sum;
            right_index = i;
        }
    }
    
    
    
    SA answer;
    answer.sum = leftsum + rightsum;
    answer.start = left_index;
    answer.end = right_index;
    
    return answer;
}

SA maxi(SA l, SA r, SA c){
    if((l.sum > r.sum) && (l.sum > c.sum)) return l;
    if((r.sum > l.sum) && (r.sum > c.sum)) return r;
    return c;
}



SA max_sub_array(int arr[] , int low , int high){
    if(low == high){
        SA answer;
        answer.sum = arr[low];
        answer.start = low;
        answer.end = high;
        
        return answer;
    }
    
    int mid = (low + high) / 2;
    
    SA left_subarray = max_sub_array(arr,low, mid);
    SA right_subarray = max_sub_array(arr,mid+1,high);
    SA mid_subarray = mid_sub_array(arr,low,mid,high);
    
    SA answer = maxi(left_subarray,right_subarray,mid_subarray);
    
    return answer;
}


int main(){
    
    int arr[6] = {-1,2,3,1,-2,3};
    SA final_ans = max_sub_array(arr,0,5);
    
    cout << "maximum subarray sum is : " << final_ans.sum << endl;
    cout << "and the maximum subarray is : " ;
    for(int i = final_ans.start ; i <= final_ans.end ; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
}
