#include<iostream>
using namespace std;
int minCostPath3(int** input , int n,int m){
    int **output = new int*[n];
    for(int i = 0 ; i <n;i++){
        output[i] = new int[m];
    }
    output[0][0] = input[0][0];
    for(int i = 1 ; i < n;i++){
        output[i][0]= input[i][0] + output[i-1][0];
        cout<<output[i][0]<<" ";
    }
    for(int i = 1 ; i < m;i++){
        output[0][i]= input[0][i] + output[0][i-1];
    }

    for(int i = 1 ; i <n;i++){
        for(int j = i; j <m;j++){    
            output[i][j] = min(output[i-1][j] , min(output[i-1][j-1], output[i][j-1])) + input[i][j];
            cout<<output[i][j]<<" ";
                    }
    }
    return output[n-1][m-1];
}
int minCostPath2(int **input,int n,int m ,int i , int j,int** output){  /// memoization
    if(i==n-1 && j==m-1){
        return input[i][j];
    }
    if(i>=n || j>=m){
        return INT16_MAX;
    }
    if(output[i][j]!=-1){
        return output[i][j];
    }

    int a = minCostPath2(input,n,m,i,j+1,output);
    int b = minCostPath2(input,n,m,i+1,j,output);
    int c = minCostPath2(input,n,m,i+1,j+1,output);

    output[i][j]=  min(a,min(b,c)) + input[i][j];
    return output[i][j] ;
}
int minCostPathHelper(int** input,int n,int m ,int i ,int j){
    int **output = new int*[n];
    for(int i = 0 ; i <n;i++){
        output[i] = new int[m];
        for(int j = 0 ; j < m;j++){
            output[i][j] = -1;
        }
    }
    return minCostPath2(input,n,m,i,j,output);
}
int minCostPath1(int **input,int n,int m ,int i , int j){
    if(i==n-1 && j==m-1){
        return input[i][j];
    }
    if(i>=n || j>=m){
        return INT16_MAX;
    }

    int a = minCostPath1(input,n,m,i,j+1);
    int b = minCostPath1(input,n,m,i+1,j);
    int c = minCostPath1(input,n,m,i+1,j+1);

    int ans =  min(a,min(b,c)) + input[i][j];
    return ans ;
}
int main(){
     int n,m;
    cin>>n>>m;
    int **input = new int*[n];
    for(int i = 0 ; i <n;i++){
        input[i] = new int[m];
        for(int j = 0 ; j < m;j++){
            cin>>input[i][j];
        }
    }
        cout<<"ans : " <<minCostPath3(input,n,m);
}