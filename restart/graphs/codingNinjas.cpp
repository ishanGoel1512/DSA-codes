#include<iostream>
#include<string>
using namespace std;
bool codingNinjas(int** edges , int i , int j , int m , int n , bool** visited){
        
}
int main(){
    int n , m ;
    char s; 
    cin>>n>>m;
    int **edges = new int*[n];
   bool **visited = new bool*[n];
    for(int i = 0 ;i<n;i++){
        edges[i] = new int[m];
        visited[i] = new bool[m];
        for(int j = 0 ; j < m ;j++){
            cin>>s;
            edges[i][j] = s;
            visited[i][j] = false; 
        }
    }
    string t = 'CODINGNINJA';
   for(int i = 0 ; i < n ; i++){
       for(int j = 0 ; j < m ;j++){
            if(edges[i][j]== t[0]){
                bool path = codingNinjas(edges,i,j,n,m,visited);
            }
       }
   }
    

}