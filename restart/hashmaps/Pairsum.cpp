#include<iostream>
#include<unordered_map>
using namespace std;
int PairSum(int *a, int n) {	 

    unordered_map<int,int> m;

    for(int i=0 ;i<n ;i++){
        m[a[i]]++;
    } 
    int count = 0 ; 
    for(int i = 0 ; i < n;i++){
        if(m[a[i]]>0){
             if(m.find(-a[i])!=m.end()){
            count++;
            m[-a[i]]=0;
        }
        else{
            continue;
        }
        }
        else{
            continue;
        }
    }
    return count;

}
int main(){

    int a[] ={2,1,2,-2,5};
    cout<<PairSum(a,5);
}