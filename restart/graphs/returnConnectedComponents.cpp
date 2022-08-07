#include<iostream>
using namespace std;
#include<queue>
void printDFS(int **edges , int n , int sv , bool* visited, vector<vector<int>*> ans){
    cout<<sv<<endl;
    visited[sv] = true ;
    for(int i = 0; i < n ;i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            ans[i]->at(i) 
            printDFS(edges,n,i,visited);
        }
    }
}
vector<vector<int>*> DFS(int **edges , int n ){
    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false ; 
    }
    vector<vector<int>*> ans = new vector<int>*();
    for(int i = 0 ; i < n ;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited,ans);
        }
    }
    
    delete [] visited;
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
   
}