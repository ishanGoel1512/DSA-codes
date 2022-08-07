#include<iostream>
using namespace std;
bool hasPath(int** edges,int n,int sv,int e,bool* visited){
    if(edges[sv][e]==1){
        return true;
    }
    visited[sv] = true;
    bool ans = false;
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1){
              if(!visited[i]){
                  ans = hasPath(edges,n,i,e,visited);
                }
        }
        if(ans==true){
            return true;
        }
        }
    return false;
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
   cout << hasPath(edges,n,s,en,visited);

   delete [] visited;
   for(int i = 0 ; i < n;i++){
    delete [] edges[i];
   }
   delete [] edges;
}