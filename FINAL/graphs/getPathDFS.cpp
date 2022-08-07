#include<iostream>
using namespace std;
#include<vector>
vector<int> *getPath(int** edges,int n,int sv,int e,bool* visited){
    if(sv==e){
       vector<int> *output = new vector<int>();
       output->push_back(e);
       return output;
    }
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1 && !visited[i]){
            visited[i] = true;
            vector<int> *ans = getPath(edges,n,i,e,visited);
            if(ans!=NULL){
                ans->push_back(sv);
                return ans;
            }
        }
        }
    return NULL;
}
int main(){
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0 ; i < n;i++){
        edges[i] = new int[e];
        for(int j=0;j<e;j++){
            edges[i][j] = 0;
        }
    }

     for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    int s,en;
    cin>>s>>en;
  vector<int> *ans =  getPath(edges,n,s,en,visited);
  if(ans!=NULL){
     for(int i = 0 ; i < ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
  }
   
   delete [] visited;
   for(int i = 0 ; i < n;i++){
    delete [] edges[i];
   }
   delete [] edges;
}