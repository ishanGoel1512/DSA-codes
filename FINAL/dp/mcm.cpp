#include<iostream>
using namespace std;
int mcm2(int* arr , int s, int e,int** output){
        if(s==e){
        return 0;
    }
        if(s==e-1){   /// only 2 matrices
        return 0;
    }

    if(output[s][e]!=-1){
        return output[s][e];
    }
       output[s][e] = INT16_MAX;
    for(int i = s+1 ; i < e;i++){
        output[s][e] =  min(mcm2(arr,s,i,output) + mcm2(arr,i,e,output) + arr[s]*arr[i]*arr[e] , output[s][e]);
    }
    return output[s][e];
}
int mcmHelper(int *arr , int s ,int e){
          int ** output = new int*[e+1] ;
            for(int i = s ; i < e+1; i++){
                output[i] = new int[e+1];
                 for(int j = 0 ; j < e+1 ; j++){
                     output[i][j] = -1; 
        }
    }

    return mcm2(arr,0,s+e,output);
}
int mcm(int *arr , int s ,int e ){  /// recrsive approach 
    if(s==e){
        return 0;
    }
    if(s==e-1){   /// only 2 matrices
        return 0;
    }
        int ans = INT16_MAX;
    for(int i = s+1 ; i < e;i++){
        ans =  min(mcm(arr,s,i) + mcm(arr,i,e) + arr[s]*arr[i]*arr[e] , ans);
    }

    return ans;
}
int main(){
    int n ;
    cin>>n;
    int* arr = new int[n+1];
    for(int i = 0 ; i < n+1;i++){
        cin>>arr[i] ;
    }

    cout<<mcmHelper(arr,0,n);
}