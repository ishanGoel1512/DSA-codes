using namespace std;
#include<vector>
class PriorityQueue
{
    vector<int> pq ; 


    public:
    PriorityQueue()
{

}
bool isEmpty()
{
    return pq.size==0;
}
int size()
{
    return pq.size;
}
int getMin()
{
    if(isEmpty())
    {
        return 0 ;
    }
    return pq[0];
}
void insert(int element)
{
    pq.push_back(element);
    int childIndex =  pq.size()-1 ;
    while(childIndex>0)
    {
    int parentIndex =  (childIndex - 1)/ 2 ; 
    if(pq[childIndex]> pq[parentIndex]) 
    {
           int temp = pq[parentIndex] ;
           pq[parentIndex] = pq[childIndex] ; 
            pq[childIndex] = temp ;
    }
    else{
        break ; 
    }
    childIndex = parentIndex ; 
    }
} 
int RemoveMin()
{
    int ans = pq[0];
    int parentIndex = 0 ; 
    pq[0] = pq[pq.size()-1];
    pq.pop_back;
    int lci = 2*parentIndex + 1 ; 
    int rci = 2*parentIndex + 2 ; 
    int temp  = min(pq[parentIndex],(pq[lci],pq[rci]));





    return ans ; 
}

};