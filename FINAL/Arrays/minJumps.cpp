#include<iostream>
using namespace std;
int minJumps(int* a ,int n , int start , int end){
        if(a[start] >= end){
            return 1;
        }

        int res = INT16_MAX;
            for(int i = start ; i < n - a[start] ; i++){
               if(i + a[i] >= end){
                    int sub_ans = minJumps(a,n,start + 1 , end);
                   if(sub_ans!=INT16_MAX){
                       res = min(sub_ans + 1,res);
                   }
               }
            }
            return res;

}
int main(){
    int a[] = {3 ,3 ,5, 4 ,3 ,9 ,6 , 7 };
    cout<< minJumps(a,8,0,7);

}