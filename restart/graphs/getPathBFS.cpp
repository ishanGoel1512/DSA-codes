#include <iostream>
using namespace std;
#include <queue>
#include<unordered_map>
vector<int>* getPathBFS(int** edges , int n , int sv,int ev , bool* visited){

    queue<int> pendingVertices ;
    pendingVertices.push(sv);
    visited[sv] = true ; 
     bool done = false;  // /just to not traverse the whole adjacency matrix 
    unordered_map<int,int> t ;
    while(!pendingVertices.empty() && !done){
        int top = pendingVertices.front();
        pendingVertices.pop();

        for(int i = 0 ; i < n ;i++){
            if(edges[top][i] == 1 && !visited[i]){
                t[i] = top ;
                visited[i] = true;
                pendingVertices.push(i);
                if(i == ev){
                    done = true;
                    break; 
                   
                }
            }
        }
    } 
    if(!done)
    return NULL;
    vector<int>* ans = new vector<int>(); 
    ans->push_back(ev);
    while(ev!=sv){
        ev = t[ev];
        ans->push_back(ev);
    }
  return ans;

}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {

        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    
  vector<int> *ans=getPathBFS(edges,n,1,3,visited);
    if(ans!=nullptr){
    for(int i=0;i<ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
    }
}