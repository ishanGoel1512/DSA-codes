#include<iostream>
using namespace std;
#include<queue>
vector<int>* getPathBFS(int** edges,int n,int sv,bool* visited ){

        queue<int> adjNodes;
        adjNodes.push(sv);
        visited[sv] = true;
        while(adjNodes.size()!=0){
            int front = adjNodes.front();
            adjNodes.pop();
            for(int i = 0 ; i < n;i++){
                if(edges[front][i]==1){
                    if(visited[i]){
                        continue;
                    }
                    adjNodes.push(i);
                    visited[i] = true;
                }
                 
        }
}
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
  vector<int> *ans =  getPathBFS(edges,n,s,en,visited);
  if(ans!=NULL){
     for(int i = 0 ; i < ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
  }

   delete [] visited;
   for(int i = 0 ; i < n ;i++){
    delete [] edges[i];
   }
   delete [] edges;
}