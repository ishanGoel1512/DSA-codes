#include<iostream>
using namespace std;
int BinarySearch(int *arr , int l ,int r ,int x){
 if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return BinarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return BinarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
int main(){
    int n; 
    cin >> n ; 
    int *a = new int[n];
    for(int i = 0 ; i < n ;i++){
        cin>>a[i];
    }    
        int x ;
        cin >> x;
        cout << BinarySearch(a,0,n-1,x) << endl;
}