#include<iostream>
#include<unordered_map>
using namespace std;
int LongestSubsetZero(int *a , int size){

    unordered_map<int,int> m;
     int sum = 0 ; 
     int maxlength = 0 ; 
    for(int i = 0 ; i < size ; i++){
        sum+= a[i];
        if(m.find(sum)!=m.end()){
            maxlength = max(maxlength,i - m[sum]);
        }
        else{
            m[sum]=i;
        }
    }
        return maxlength;
            

}
int main(){
    int a[]={ 95,-97,-387,-435,-5,-70,897,127,23,284};
    cout<<LongestSubsetZero(a,10);
}