#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> LongestConsSeq(int *a ,int size){
    unordered_map<int,int> m;
    for(int i = 0; i < size ; i++){
        m[a[i]] = true;
    }
    int maxlength=0; 
    int start=0 ; 
    int end=0 ; 
    for(int i = 0 ; i < size ; i++){
            if(m[a[i]]==true){ 
                if(m.find(a[i] - 1) != m.end()){
                continue;
            }
            else{
                int next = a[i];
                while(m.find(next)!=m.end()){
                     m[next]=false;
                    next++;
                   
                }
            if(maxlength < next -a[i]){
                maxlength = next - a[i];
                start = a[i];
                end = next - 1;
            }
           }}
           else{
               continue;
           }
           
        }
  return {start,end};
}
//2 12 9 16 10 5 3 20 25 11 1 8 6

int main(){
    int a[]={2,12,9,16,10,5,3,20,25,11,1,8,6};
    vector<int> output = LongestConsSeq(a,13);
    for(int i = 0 ;i < output.size();i++ ){
        cout<< output[i] <<" ";
    }
    
}