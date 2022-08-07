#include<iostream>
using namespace std;
int minCostPath2(int **input , int m , int n , int i , int j,int **output){

    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >=m || j>=n){
        return INT16_MAX;
    }
    //check if ans already exists
    if(output[i][j] !=-1){
        return output[i][j];
    }
     // recursive calls 
     int x = minCostPath2(input,m,n,i,j+1,output);
     int y = minCostPath2(input,m,n,i+1,j+1,output);
     int z = minCostPath2(input,m,n,i+1,j,output);

     ///Small calculation 
     int a = min(x , min(y,z)) + input[i][j];
     //save the answer for future use 
     output[i][j] = a;
     return a;

}
int minCostPath2(int **input , int m , int n , int i , int j){
      int **output = new int*[m];
    for(int i=0 ; i < m ;i++){
        output[i] = new int[n];
        for(int j = 0 ; j < n ;j++){
            output[i][j] = -1;
        }
    }

    return minCostPath2(input,m,n,i,j,output);

}
int minCostPath(int **input , int m , int n , int i , int j ){

    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >=m || j>=n){
        return INT16_MAX;
    }

     // recursive calls 
     int x = minCostPath(input,m,n,i,j+1);
     int y = minCostPath(input,m,n,i+1,j+1);
     int z = minCostPath(input,m,n,i+1,j);

     ///Small calculation 
     int ans = min(x , min(y,z)) + input[i][j];
     return ans;

}
int minCostPath(int **input , int m , int n ){
    return minCostPath(input,m,n,0,0);
}
int main(){
    int m , n ; 
    cin>>m>>n;
    int **input = new int*[m];
    for(int i=0 ; i < m ;i++){
        input[i] = new int[n];
        for(int j = 0 ; j < n ;j++){
            cin>>input[i][j];
        }
    }
    cout<< minCostPath(input,m,n) <<endl;
    cout<< minCostPath2(input,m,n,0,0) <<endl;
}