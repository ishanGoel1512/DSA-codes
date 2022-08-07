class StackUsingArray
{
private:
int *data;
int nextIndex;
int capacity ; 
public:
StackUsingArray()
{
    data = new int[4];
    nextIndex = 0 ; 
    capacity = 4 ; 
}
//return the elemnts in the stack
int size()
{
    return nextIndex; 
}

bool is_Empty()
{
    return nextIndex==0;
}
//insert element
void push(int n)
{
    if(capacity==nextIndex)
    {
          /*cout<<"Stack Full "<<endl;
          return ;
          */
         int *newData= new int[2*capacity];
         for(int i =0 ; i<capacity; i++)
         {
             newData[i] =data[i] ;
         } 
         capacity*=2;
         delete [] data;
         data=newData;
    }      
    data[nextIndex]=n;
    nextIndex++;

}
//delete the element
int pop(){
    nextIndex--;
    return data[nextIndex];
    if(nextIndex==0)
    {    cout<<"Stack is Empty"<<endl;
        return -1; 
    }
}
//topmost element 
int top()
{
    
    if(nextIndex==0)
    {    cout<<"Stack is Empty"<<endl;
        return -1 ; 
    }
    return data[nextIndex-1];
}

};
