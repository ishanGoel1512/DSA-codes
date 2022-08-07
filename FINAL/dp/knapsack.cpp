#include<iostream>
using namespace std;
int knapsack2(int n , int*w ,int* v,int maxW,int* output){
     if(maxW==0 || n==0){
        return 0;
    }
    if(output[n-1]!= -1){
        return output[n-1];
    }
    if(w[0] > maxW){
        output[n-1] = knapsack2(n,w,v,maxW,output);
       return output[n-1];
    }
    int smallAns1 = v[0] + knapsack2(n-1,w+1,v+1,maxW-w[0],output);
    int smallAns2 = knapsack2(n-1,w+1,v+1,maxW,output);

    output[n-1] =  max(smallAns1,smallAns2);
    return output[n-1];
}
int knapsackHelper(int n , int* w ,int* v,int maxW){
        int *output = new int[n];
        for(int i = 0;i<n;i++){
            output[i] = -1 ;
           
        }

       return knapsack2(n,w,v,maxW,output); 
}
int knapsack(int n , int* w,int* v,int maxW){
    if(maxW==0 || n==0){
        return 0;
    }
    if(w[0] > maxW){
        return knapsack(n-1,w+1,v+1,maxW);
    }
    int smallAns1 = v[0] + knapsack(n-1,w+1,v+1,maxW-w[0]);
    int smallAns2 = knapsack(n-1,w+1,v+1,maxW);

    return max(smallAns1,smallAns2);
}
int main(){
    int n;
    cin>>n;
    int *w = new int[n];
    int *v = new int[n];
    for(int i = 0 ; i < n;i++){
        cin>>w[i];
    }
    for(int i = 0 ; i < n;i++){
        cin>>v[i];
    }
    int maxW;
    cin>>maxW;
    cout<< knapsackHelper(n,w,v,maxW);

}