#include<iostream>
using namespace std;
int minStepstoOne(int n ){

    //Base case
    if(n<=1){
        return 0;
    }

    // recursive calls
   
    int y=INT16_MAX;
    int z=INT16_MAX;
    int x = minStepstoOne(n-1);
    if(n%2==0){
        y = minStepstoOne(n/2);
    }
     if(n%3==0){
        z = minStepstoOne(n/3);
    }
        return 1 + min(x,min(y,z));

}
int main(){
    int n;
    cin>>n;
    cout<<minStepstoOne(n);
}