#include<iostream>
using namespace std;
void inPlaceHeapSort(int *pq , int n){

    //Insert
        for(int i = 0 ; i < n;i++){
           int childIndex = i;

     while(childIndex > 0 ){
         int parentIndex = (childIndex - 1)/2;
         
         if(pq[childIndex]<pq[parentIndex])
         {
         int temp = pq[childIndex];
         pq[childIndex] = pq[parentIndex];
         pq[parentIndex] = temp;
        }
        else{
            break;
        }

     childIndex = parentIndex;
     }
        }

//Delete
      int size = n;
      while(size > 1){
      int temp = pq[0];
      pq[0] = pq[size - 1];
      pq[size-1] = temp ; 
      size--;
// Down Heapify
    int parentIndex = 0 ;
   
    int leftChild = 2*parentIndex + 1;
    int rightChild = 2*parentIndex + 2;

    while(leftChild < size){
    int minIndex = parentIndex;
    if(pq[minIndex] > pq[leftChild]){
        minIndex = leftChild;
    }
    if(rightChild < size && pq[minIndex] > pq[rightChild]){
        minIndex = rightChild;
    }   
        if(parentIndex == minIndex){
            break;
        }
        int temp = pq[minIndex];
        pq[minIndex] = pq[parentIndex];
        pq[parentIndex] = temp;

        parentIndex = minIndex;
         leftChild = 2*parentIndex + 1;
         rightChild = 2*parentIndex + 2;
    }
      }        
        


}
int main(){
    int a[]={10,3,4,5,2,8,7,6};
    inPlaceHeapSort(a,8);
    for(int i = 0 ; i < 8;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}