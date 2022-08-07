#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Triplet{
    public:
    int element; 
    int AIndex;
    int EIndex;
    
    
};
vector<int> KsortedArrays(vector<vector<int>*> a){

    priority_queue<Triplet , vector<Triplet>, greater<Triplet>> pq;
    vector<int> output;
    for(int i = 0; i <a.size() ; i++){
        Triplet Init;
        Init.element = a[i]->at(0);
        Init.AIndex = i;
        Init.EIndex = 0;
        pq.push(Init);
    }
    while(!pq.empty()){
       Triplet top = pq.top();
        pq.pop();
        output.push_back(top.element);
        Triplet ans;
        ans.AIndex = top.AIndex;
        ans.EIndex = top.EIndex;
        ans.element = a[ans.AIndex]->at(ans.EIndex + 1);
        if(ans.EIndex + 1 < a[ans.AIndex]->size()){
            pq.push(ans);
        }
    }
 return output;
}
int main(){

        // int a1[] = {1,5,9};
        // int a2[] = {45,90};
        // int a3[] = {2,6,78,100,234};
        // int a4[] = {0};
        // vector<int> output = KsortedArrays(a1,a2,a3,a4,3,2,5,1,4);
        // for(int i = 0 ; i < 11 ; i++){
        //     cout<<output[i]<<" ";
        // }
        
}