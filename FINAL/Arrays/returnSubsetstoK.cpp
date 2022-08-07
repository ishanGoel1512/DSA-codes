#include<iostream>
using namespace std;
int returnSubsetstoK(int input[] , int n ,int k , int output[][20]){

    // base case
     if(n==0){
        if(k==0){
            output[0][0] = 0; 
            return 1; 
        }
        else
            return 0 ;
     }

    // recursive calls 
        int o1[20][20] ; 
        int o2[20][20] ;
        int s1 = returnSubsetstoK(input + 1 , n-1 , k , o1);
        int s2 = returnSubsetstoK(input + 1 , n-1 , k - input[0] , o2);
       
    // small calcualtion
       int rowCount=0;
    for(int i=0 ;i<s1;i++)
    {
        for(int j=0 ;j<=o1[i][0];j++)
        {
           output[rowCount][j]=o1[i][j];
        }
        rowCount++;
    }
    for(int i=0 ;i<s2;i++)
    {
        output[rowCount][0]=o2[i][0]+1;
        output[rowCount][1] = input[0];
        for(int j=1 ;j<=o2[i][0];j++)
        {
           output[rowCount][j+1]=o2[i][j];
        }
        rowCount++;
    }
    return rowCount;
}
int main(){
     
     int n;
     int output[20][20];
     cin >> n;
     int input[n];
     for(int i=0; i < n; i++){
     cin >> input[i];
     }
     int k; 
     cin>>k;
     int size = returnSubsetstoK(input,n,k, output);
     for( int i = 0; i < size; i++) {
     for( int j = 1; j <= output[i][0]; j++) {
        cout << output[i][j] << " ";
     }
     cout << endl;
  }
}
