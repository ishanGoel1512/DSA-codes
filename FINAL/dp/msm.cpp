#include<iostream>
using namespace std;
int msm(int **input , int n,int m){
        int **output = new int*[n];
             for(int i = 0 ; i <n;i++){
                    output[i] = new int[m];
                for(int j = 0 ; j < m;j++){
                     output[i][j] = 0;
        }   
    }

    for(int i = 0 ; i < m;i++){
        if(input[0][i] == 0){
            output[0][i] = 1;
        }
    }
    for(int j = 0 ; j < n;j++){
        if(input[j][0] == 0){
            output[j][0] = 1;
        }
    }

    for(int i = 1 ; i < n;i++){
        for(int j = 1 ; j < m;j++){
            if(input[i][j] == 1){
                output[i][j] = 0;
                continue;
            }
            output[i][j] = min(output[i-1][j],min(output[i][j-1] , output[i-1][j-1])) + 1;
        }
    }
    int ans = INT16_MIN;
    for(int i = 0;i<n;i++){
        for(int j = 0 ;j<m;j++){
                ans = max(output[i][j] , ans);
        }
    }
    return ans;
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
        cout<< msm(input,n,m);

}