using namespace std;
#include<vector>
class PriorityQueue{
    public:
    vector<int> pq; 
    PriorityQueue(){

    }

   bool isEmpty(){
    return pq.size()==0;
   } 
   int getSize(){
       return pq.size();
   }
   int getMax(){
       if(isEmpty()){
           return 0;;
       }
       return pq[0];
   }
   void insert(int data){
       
       int childIndex = pq.size() - 1;

       while(childIndex > 0 ){
           int parentIndex = (childIndex - 1)/2 ;
           if(pq[parentIndex] < pq[childIndex]){
               int temp = pq[parentIndex];
               pq[parentIndex] = pq[childIndex];
               pq[childIndex] = temp;
           }
           else{
               break;
           }
            childIndex = parentIndex;
       }
   }

  int RemoveMax(){
      int ans = pq[0];
      pq[0] = pq[pq.size() - 1];
      pq.pop_back();
      int parentIndex = 0;
      int leftChildIndex = 2*parentIndex + 1 ;
      int rightChildIndex = 2*parentIndex + 2; 
      while(leftChildIndex < pq.size()){
          int maxIndex = parentIndex;
          if(pq[maxIndex] < pq[leftChildIndex]){
              maxIndex = leftChildIndex;
          }
            if(pq[maxIndex] < pq[rightChildIndex] && pq.size() > rightChildIndex){
                maxIndex = rightChildIndex;
            }
            if(parentIndex == maxIndex){
                break;
            }
          int temp = pq[maxIndex];
               pq[parentIndex] = pq[maxIndex];
               pq[maxIndex] = temp;

             parentIndex = maxIndex;
             leftChildIndex = 2*parentIndex + 1 ;
             rightChildIndex = 2*parentIndex + 2; 

      }
      return ans; 
  } 

};