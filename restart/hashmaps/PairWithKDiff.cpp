#include<iostream>
#include<unordered_map>

using namespace std;
// Using Hashmaps
int PairK(int *a , int size , int k){  /// not considering corner cases
    unordered_map<int,int> m;
    for(int i = 0 ; i < size;i++){  /// inserting keys into hashmaps 
        m[a[i]]++;
    }
    int count=0;
    unordered_map<int,int> :: iterator it;
    for(it =m.begin(); it!=m.end() ; it++){

        if(m.find(it->first - k) != m.end() ){
            count+= it->second*m[it->first - k];
        }
        if(m.find(it->first + k) != m.end()){
            count+= it->second*m[it->first + k];
        }
            
        m[it->first] = 0 ;
    }
    return count;
}
int main(){
    int a[] = {5,1,2,4};
    cout<<PairK(a,4,3)<<endl;
}