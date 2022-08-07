#include<iostream>
using namespace std;
#include<vector>
vector<int>* getPath(int **edges , int n , int sv ,int ev,bool *visited){
  
       
        if(sv == ev){
        vector<int>* ans = new vector<int>() ; 
        ans->push_back(ev);
        return ans;
        }
             visited[sv] = true;
    
            for(int i = 0 ; i < n ; i++){
                if(edges[sv][i] == 1 && !visited[i]){
                    visited[i] = true; 
                        vector<int>* temp = getPath(edges,n,i,ev,visited);
               if(temp!=NULL){
                    temp->push_back(sv);
                    return temp;
               }
                }
            }
   
          return NULL;
}
int main(){
      int n , e ; 
    cin>>n>>e;
    int ** edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            edges[i][j] = 0 ; 
        }
    }
    for(int i = 0 ; i< e;i++){

        int f,s ;
        cin>> f >> s;
        edges[f][s] = 1 ; 
        edges[s][f] = 1 ;
    }
      bool* visited = new bool[n];
    for(int i = 0;i<n;i++){
        visited[i] = false ; 
    }

  vector<int> *ans=getPath(edges,n,1,3,visited);
    if(ans!=nullptr){
    for(int i=0;i<ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
    }
}