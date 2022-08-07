#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> removDup(int *a , int size)
{
    vector<int> output;
    unordered_map<int,bool> seen; 
    for(int i=0; i<size,i++)
    {
          if(seen.count(a[i])>0)
          {
              continue;
          }
               seen[a[i]]=true ;
               output.push_back(a[i]);

    }
    return output;
}
int main()
{

}