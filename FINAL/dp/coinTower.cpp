#include<iostream>
using namespace std;
#include<string>
bool coinTower2(int n,int x,int y){

    int *output = new int[n];
    for(int i = 0 ; i < n;i++){
        output[i] = 0;
    }
    for(int i = 2;i < n;i++){
        if(i > x && i > y){
            output[i] = max(output[i-1]^1,max(output[i-x]^1,output[i-y]^1));
        }
        else{
            output[i] = output[i-1]^1;
        }
        
    }
    return output[n];    
}
bool coinTower(int n,int x,int y){
    if(n==x || n==y ){
        return 1;
    }
   if(n<=0){
    return 0;
   }
    int a = coinTower(n-1,x,y);
    int b = coinTower(n-x,x,y);
    int c = coinTower(n-y,x,y);

    return max(a^1,max(b^1,c^1));
}    
void coinTowerHelper(int n ,int x, int y){

        bool ans = coinTower2(n,x,y);
        if(ans==1){
            cout<< 'B';
        }
        else{
            cout<<'W';
        }
}
int main(){
    int n , x , y;
    cin>>n>>x>>y;
   coinTowerHelper(n,x,y);
}