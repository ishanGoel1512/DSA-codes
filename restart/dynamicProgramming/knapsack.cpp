#include<iostream>
using namespace std;
int knapsack(int n , int* w , int *v , int mw){

        ///Base Case
        if(n==0 || mw==0){
            return 0 ;
        } 
        if(w[0] > mw){
            return knapsack(n-1,w+1,v+1,mw);
        }
        /// recursive calls 
        int a = v[0] + knapsack(n-1,w+1,v+1,mw-w[0]);
        int b = knapsack(n-1,w+1,v+1,mw);
        return max(a,b);

}
int main(){
    int n ; 
    int w[] = { 5,1,8,9,2};
    int v[] = { 4,10,2,3,1};
    int W = 15;
    cout<< knapsack(5,w,v,W)<<endl;
}