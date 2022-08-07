#include<iostream>
using namespace std;
#include <queue>
#include "binary_tree.h"
BinaryTreeNode<int>* takeInputLevelWise()    ////  INPUT LEVELWISE USING QUEUE 
{
    int rootData ; 
    cout<<"Enter root data"<<endl;
    cin>>rootData ;
    if(rootData==-1)
{
    return NULL ;
}
   BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue <BinaryTreeNode<int>*> PendingNodes;
    PendingNodes.push(root);
    while(PendingNodes.size()!=0){
        BinaryTreeNode<int>* front = PendingNodes.front();
        PendingNodes.pop();
    int leftchild;
    cout<<"Enter the left child of "<<front->data<<endl;
    cin>>leftchild;
    if(leftchild!=-1)
    {
        BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchild);
        front->left = child ; 
        PendingNodes.push(child);
    }
    int rightchild;
    cout<<"Enter the right child of "<<front->data<<endl;
    cin>>rightchild;
    if(rightchild!=-1)
    {
        BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightchild);
        front->right = child ; 
        PendingNodes.push(child);
    }
    }
    return root; 

}
void LevelWiseprint(BinaryTreeNode<int> * root)        /////LEVEL WISE PRINTING
{     if(root==NULL)
{
    return ;
}
   
     queue<BinaryTreeNode<int>*> pending;
     BinaryTreeNode<int>* front ;
     pending.push(root);
     pending.push(NULL);
     
    while(pending.size()>1)
    {  
        front = pending.front();
        pending.pop();
        if(front==NULL)
        {   pending.push(NULL) ;
            cout<<endl;
        }
        else{
        if(front->left!=NULL)
        {
            pending.push(front->left);
        }
        if(front->right!=NULL)
        {
            pending.push(front->right);
        }
        cout<<front->data<<" ";
        }

    }
}
bool SearchBST(BinaryTreeNode<int>* root,int x)   ////  SEARCH BST
{   if(root==NULL)
{
    return 0; 
}
   if(x==root->data)
   {
       return 1;
   }
   if(x>root->data)
   {
      bool p = SearchBST(root->right,x);
      return p;
   }
   if(x<root->data)
   {
       bool p = SearchBST(root->left,x);
       return p ; 
   }
}
BinaryTreeNode<int>* printInRange(BinaryTreeNode<int>* root,int ll,int ul)  /// PRINT IN RANGE 
{
    if(root==NULL)
    {
        return NULL ;
    }
     if(root->data>=ll)
    
     {
         BinaryTreeNode<int>* p =printInRange(root->left,ll,ul);
         return p ;
         } 
        
 
      if(root->data<=ll)
    {
         BinaryTreeNode<int>* p =printInRange(root->right,ll,ul);
         return p ;
     } 
     
     
}
int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT16_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT16_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root)                 /// BST CHECK 
{
    if(root==NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

BinaryTreeNode<int>* constructTree(int a[],int n)
{
    if(n==0)
    {
        return NULL ;
    }
    
        BinaryTreeNode<int>* root;
        root->data = a[(n+1)/2];
        root->left==constructTree(a,(n + 1)/4);
        root->right==constructTree(a,(3*n+1)/4);
        return root;

    
}
int main()
{
  /*  BinaryTreeNode<int>* root = takeInputLevelWise();
    LevelWiseprint(root);
    cout<<isBST(root);
    */
   int a[]={1,2,3,4,5,6,7};
   int n = 7;
   BinaryTreeNode<int>* root = constructTree(a,7);
   LevelWiseprint(root);
}