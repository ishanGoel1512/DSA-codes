#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 
int frequency(int *a , int size){
    unordered_map<int,int> seen ; 
    int max = 0 ; 
    int ans=0 ; 
    for(int i = 0 ; i < size;i++){
        if(seen.count(a[i])> 0 ){
            seen[a[i]]+=1;
        }
        else{
            seen[a[i]] = 1 ; 
        }
        if(max < seen[a[i]])
        {
            max = seen[a[i]];
            ans = a[i];

        }
    }
    return ans ; 
}
int main(){
     int a[] = {1 ,1,3,4,3,3,3,3,3,5,5,5,5,5,5,5,2,3,4,4,4,4 ,5};
     cout<<frequency(a,23)<<endl;

}