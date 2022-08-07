#include<iostream>
using namespace std;
#include "treenode.h"
#include<queue>
class pair
{  public:
    TreeNode<int>* node ; 
    int sum ; 

pair()
{
    this->node = NULL ;
    this->sum = 0 ; 
}
};
int numNodes(TreeNode<int>* root)                      /// NUMBER OF NODES 
{
     int ans =1 ;
     for(int i=0; i<root->children.size();i++)
{
    ans+=numNodes(root->children[i]);
    }
   return ans;
}

void print_levelwise(TreeNode<int> * root)                   //  PRINT LEVEWISE
{
    queue<TreeNode<int>*> printing;
    printing.push(root);
    while(printing.size()!=0)
    {    TreeNode<int> *front = printing.front();
         printing.pop();
         cout<<front->data<<":";
       for(int i = 0 ; i<front->children.size(); i++)
       {
           cout<<front->children[i]->data<<",";
           printing.push(front->children[i]);

       }
       cout<<endl;
    }


}
TreeNode<int>* take_Input_levelwise()                 /// INPUT LEVEL WISE
{
    int rootData;
    cout<<"Enter root Data : "<<endl; 
    cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter the no. of children of"<<front->data <<endl;
        int numchild;
        cin>>numchild;
        for(int i = 0; i<numchild; i++)
        {   int childData;
            cout<<"enter the "<<i << " of the "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;


}
TreeNode<int> * takeInput()                          //// INPUT NORMAL
{
     int rootData ; 
     cout<<"Enter Data : "<<endl;
     cin>>rootData ;
     TreeNode <int> * root = new TreeNode<int>(rootData);
     int n ;
     cout<<"Enter the number of children of "<<rootData<<endl;
     cin>>n;
     for(int i = 0 ; i < n ;i++)
     {
         TreeNode <int>* child = takeInput();
         root->children.push_back(child);
     }
     return root ; 


} 
void print(TreeNode<int>* root)                  // PRINT NORMAL
{    
    
    cout<<root->data<<":" ;
     for(int i = 0 ; i< root->children.size();i++)
    {
        cout<<root->children[i]->data<<"," ;
    }
    cout<<endl;
    for(int i = 0 ; i< root->children.size();i++)
    {
        print(root->children[i]);
    }
} 
int sumNodes(TreeNode<int>* root)        // SUM OF NODES
{
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {   
        sum+= sumNodes(root->children[i]);
    }
    return sum;
}
int max_Node(TreeNode<int>* root)                  ///// MAX OF NODES
{             
  int max = root->data;

    if(root==NULL)
    {
        return 0;
    }


for(int i = 0; i<root->children.size();i++)
{
    if(root->children[i]->data>max)
    {
        max=root->children[i]->data;
    
    
    }
   
}
int max_2=0;
for(int i= 0;i<root->children.size();i++)
{
    max_2 =  max_Node(root->children[i]);
}
if(max_2<root->data)
{
    max_2 = root->data ;
}


return max_2;

    
}
int leaf_Nodes(TreeNode<int>* root)
{    
     if( root == NULL ){
         return 0;
      }

       if( root->children.size() == 0 ) {
          return 1;
       }

      int count = 0;
      for( int i = 0 ; i<root->children.size();i++ ) {
          count += leaf_Nodes(root->children[i]);
      }

      return count;
}
int height_Node(TreeNode<int>* root)        /// HEIGHT OF A TREE
{      
    
    if( root == NULL ){
         return 0;
      }

       if( root->children.size() == 0 ) {
          return 1;
       }
       int max = 0 ;
      int ans= 0;
       for( int i = 0 ; i<root->children.size();i++ )
       {
               ans+= leaf_Nodes(root->children[i]);
               if(ans>max)
               {
                   max=ans;
               }
               
               
       }
       int max_2 = max-1;
       return max_2;
       

}


void post_order(TreeNode<int> * root)      // POST ORDER TRAVERSAL
{
    if(root==NULL)
    {
        return;
    }
   for(int  i = 0 ; i<root->children.size();i++)
   {
       post_order(root->children[i]);
   }
   cout<<root->data<<" ";
    

}
void pre_order(TreeNode<int> * root)        //  PRE ORDER TRAVERSAL
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
   for(int  i = 0 ; i<root->children.size();i++)
   {
       pre_order(root->children[i]);
   }
   
    

}
int count_x(TreeNode<int> * root , int x)
{       
        int count = 0 ;
       if(root==NULL)
       {
           return 0 ;
       }
       if(root->data>x)
       {
          count++;

       }
       for(int  i = 0 ; i<root->children.size();i++)
       {  
         
         count+= count_x(root->children[i],x);
         

       }
       return count;
       
}


int find_x(TreeNode<int>* root , int x)
{   
    if(root==NULL)
    {
        return 0 ; 
    }
      int count = 0 ; 
     if(root->data > x )
     {
         count++ ; 
     }
         for(int i = 0 ; i < root->children.size();i++)
     {
      count+= find_x(root->children[i],x);
     }
     return count; 
     
}
/*TreeNode<int>* Node_Max(TreeNode<int>* root)
{
    if(root==NULL);
    {
        return NULL ; 
    }
    int sum = root->data ; 
    for(int i = 0 ; i < root->children[i];i++)
    {
        sum+= root->children[i]->data ; 
    }
       
      


}

TreeNode<int>* Node_Max(<TreeNode<int>* root)
{
      if(root == NULL)
      {
         pair ans; 
          ans.node = NULL ; 
          ans.sum = root->data ; 
          return ans ; 
      }

      pair ans1; 
      ans1.node = root ; 
      
      for(int i = 0 ; i < root->children.size();i++)
      {
              ans1.sum + = root->children[i]->data ; 
      }
      for(int i = 0 ; i < root->childen.size(); i++)
      {
      pair smallAns = Node_Max(root->children[i]);
       smallAns.sum = max(ans.sum , smallAns.sum);
       smallAns.root = root->children[i];
      }

      pair ans2 ; 
      ans2.node = smallAns->node ; 
      ans2.sum = smallAns->sum ; 
      return ans2 ; 
      
}
TreeNode<int>* ans = NULL ;
TreeNode<int>* smallAns = NULL ; 
TreeNode<int>* Next_Larger(TreeNode<int>* root , int x)
{
       if(root==NULL)
       {
           return NULL ; 
       }
       if(root->data > x)
       {
           ans = root ; 
       }
        for(int i = 0 ; i < root->children.size();i++)
        {
            smallAns = Next_Larger(root->children[i],x);

            if(smallAns==NULL)
            {
               continue ; 
            }
            if(ans == NULL || smallAns->data < ans->data)
            {
                ans = smallAns ; 
            }  

        } 
        
        return ans ; 
}*/
TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    /* Given a generic tree and an integer n. Find and return the node with next
     * larger element in the Tree i.e. find a node with value just greater than
     * n. */
    /* Solution: We need to traverse all the nodes and check for next larger
     * Node. Here we are using post Order Traversal but we may use any
     * traversal technique. */
    if(root==nullptr) 
    return nullptr;
    int childCount = root->children.size();
    if(childCount==0) // Base Case
    {
        if(root->data>n) return root; // Found node with value greater than n
        return nullptr;
    }
    TreeNode<int> *result = nullptr;
    if(root->data>n)
     result=root; // Found node with value greater than n
    for(int i=0; i<childCount; i++)
    {
        TreeNode<int> *temp = nextLargerElement(root->children[i], n);
        if(temp==nullptr) continue;
        if(result==nullptr || result->data>temp->data)
            result = temp;
    }
    return result;
}
bool is_Identical(TreeNode<int>* root1 , TreeNode<int>* root2 )   //// problem 
{
    if(root1->children.size()!=root2->children.size())
        {
            return false;
        }
         if(root1->children.size()==root2->children.size())
        {
            if(root1->data==root2->data)
            {
                for(int i=0 ,j=0;i<root1->children.size()&&j<root2->children.size();i++ ,j++){
                 bool smallAns =  is_Identical(root1->children[i],root2->children[j]);
                   return smallAns;      
                }
            }
            if(root1->data!=root2->data)
            {
                return false; 
            }
        }
        
}

TreeNode<int>* second_largest(TreeNode<int>* root)
{
    if(root==NULL || root->children.size()==0 )
    {
        return NULL ; 
    }
    int max = root->data ; 
      
for(int i = 0 ; i < root->children.size();i++)
{  
     TreeNode<int> smallAns = second_largest(root->chidlren[i]);
     if(max > root->data )
     {
        max = 
     }
}
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 
int main()
{ 
  /*TreeNode <int>* root = new TreeNode <int> (10);
    TreeNode <int>* node1 = new TreeNode <int> (20);
    TreeNode <int>* node2 = new TreeNode <int> (30);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int> *root1 = take_Input_levelwise();
    TreeNode<int> *root2 = take_Input_levelwise();
     //print_levelwise(root);
     //post_order(root);
    cout<<is_Identical(root1,root2); 
    

     
     
   // delete root ;             ///////            WHEN DELETE IS USED , CORRESPONDING OBJECT CALLS ITS DESTRUCTOR 


}