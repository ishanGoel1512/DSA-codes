#include<iostream>
using namespace std; 
int partition(int* a , int s , int e){
    /// count of no. smaller than x 
    int count = 0; 
    int pivot = a[s];
    for(int i = s+1; i <=e ;i++){
        if(a[i] <= pivot){
            count++;
        }
    }
        int pivotIndex = s + count;
        swap(a[pivotIndex] , a[s]);
        int k = e , j = s ; 
        while( k > pivotIndex && j < pivotIndex){
                if(a[j] <= a[pivotIndex])
                { 
                    j++;
                }
                else if(a[k] > a[pivotIndex])
                { 
                    k--;
                }
                else{ 
                    if(k > pivotIndex && j < pivotIndex) /// condition to be checked 
                    swap(a[j++] , a[k--]);
                }
        }
    return pivotIndex;
}
void quickSort(int* a, int s ,int e){

    // BASE CASE
    if(s>=e){
        return;
    }
    
    // SMALL CALCULATION 
    int c = partition(a,s,e);
    quickSort(a,s,c-1);
    quickSort(a,c+1,e);

}
int main(){

     int n ; 
    cin>>n;
    int *a = new int[n];
    for(int i = 0 ;i < n ; i++)
    {
    cin>>a[i];
    }
    quickSort(a,0,n-1);
    for(int i = 0; i < n ; i++){
        cout<<a[i];
    }
}