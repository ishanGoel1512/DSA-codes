#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include<algorithm>
#include<list>
#include"Node.h"
#include<stack>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()  ///  TAKE INPUT LEVEL WISE
{
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cout << "Enter the left child of " << front->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *Child = new BinaryTreeNode<int>(leftData);
            front->left = Child;
            pendingNodes.push(Child);
        }

        int rightData;
        cout << "Enter the right child of " << front->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *Child = new BinaryTreeNode<int>(rightData);
            front->right = Child;
            pendingNodes.push(Child);
        }
    }
    return root;
}
void printTreeLevelWise(BinaryTreeNode<int> *root)  ///  PRINT INPUT LEVELWISE
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        cout << front->data << ":";
        pendingNodes.pop();
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}
int countNodes(BinaryTreeNode<int>* root){    //// NO. of  NODES
        if(root==NULL){
            return 0 ; 
        }
    
      return 1 +  countNodes(root->left) + countNodes(root->right);
 }
bool isNodePresent(BinaryTreeNode<int>* root , int x){   /// is Node Present
    if(root==NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    return isNodePresent(root->left,x) || isNodePresent(root->right,x);

}
int height(BinaryTreeNode<int>* root){   /// HEIGHT
if(root==NULL){
    return 0 ; 
}
if(root->left ==NULL && root->right==NULL){
    return 1 ; 
}
    return 1 + std::max(height(root->left) , height(root->right));
}
void mirrorTree(BinaryTreeNode<int>* root){
     if(root==NULL)
       return;
    BinaryTreeNode<int>* temp=root->left;
    
    root->left=root->right;
    root->right=temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}
//TRAVERSALS
void inorder(BinaryTreeNode<int>* root){   //// INORDER   --> LEFT ROOT RIGHT
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(BinaryTreeNode<int>* root){  /// PREORDER  ---> ROOT LEFT RIGHT
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int>* root){ //// POSTORDER ----> LEFT RIGHT ROOT
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return std::max(option1 , std::max(option2 , option3));
}
pair<int , int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p; 
        p.first = 0 ;
        p.second = 0 ;
        return p ; 
    }

    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second ; 
    int rd = rightAns.second;
    int lh = leftAns.first;
    int rh = rightAns.first;

    int height = 1 + std::max(lh ,rh);
    int diameter =  max( lh + rh , max(ld,rd));
    pair<int,int> p ; 
    p.first = height ; 
    p.second = diameter;
    return p ; 
}
pair<int , int> maxAndmin(BinaryTreeNode<int>* root){

  if(root==NULL){
       pair<int , int> ans ; 
        ans.first = 0; 
        ans.second = INT16_MAX ;
        return ans ;  
  }     
  if(root->left==NULL && root->right==NULL){
        pair<int,int> p ; 
        p.first = root->data ;
        p.second = root->data ; 
        return p ;
  }
        pair<int,int> leftAns =  maxAndmin(root->left);
        pair<int,int> rightAns = maxAndmin(root->right);

        int maxm = max(root->data , max(leftAns.first , rightAns.first) );
        int minm = min(root->data , min(leftAns.second , rightAns.second));
            pair<int,int> ansAll ; 
            ansAll.first = maxm ;
            ansAll.second = minm; 
        return ansAll;
}
BinaryTreeNode<int>* buildTreeHelperPreorder(int in[] , int pre[] , int inS , int inE , int preS , int preE){
    if(inS>inE){
        return NULL; 
    }
    int rootData  = pre[preS];
    int rootIndex = -1;
    for(int i = inS ; i<=inE;i++){
        if(in[i] == rootData){
            rootIndex = i ; 
            break ; 
        }
    }

    int lpreS = preS + 1;
    int linS = inS;
    int linE = rootIndex - 1 ;
    int lpreE = linE - linS + lpreS;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = rootIndex + 1;
    int rinE = inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelperPreorder(in,pre,linS,linE,lpreS,lpreE);
    root->right = buildTreeHelperPreorder(in,pre,rinS,rinE,rpreS,rpreE);
    return root;

}
BinaryTreeNode<int>* buildTreePreorder(int in[] , int pre[] , int size){
    return buildTreeHelperPreorder(in,pre,0,size - 1,0,size - 1);
}

BinaryTreeNode<int>* buildTreeHelperPostorder(int in[] , int pos[] , int inS , int inE , int posS , int posE){
    if(inS > inE){
        return NULL; 
    }
    int rootData  = pos[posE];
    int rootIndex = -1;
    for(int i = inS ; i<=inE;i++){
        if(in[i] == rootData){
            rootIndex = i ; 
            break ; 
        }
    }
    int lposS = posS ;
    int linS = inS;
    int linE = rootIndex - 1 ;
    int lposE = +lposS +linE - linS ;
    int rposS = lposE + 1;
    int rposE = posE - 1;
    int rinS = rootIndex + 1;
    int rinE = inE ;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelperPostorder(in,pos,linS,linE,lposS,lposE);
    root->right = buildTreeHelperPostorder(in,pos,rinS,rinE,rposS,rposE);
    return root;

}
BinaryTreeNode<int>* buildTreePostorder(int in[] , int pos[] , int size){
    return buildTreeHelperPostorder(in,pos,0,size - 1,0,size - 1);
}
int sumNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0 ; 
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
bool isBalanced(BinaryTreeNode<int>* root){     /////BAD COMPLEXITY 
    if(root==NULL)
    {
    return false;
    }
    if(height(root->left) - height(root->right) <=1){
            return true ;
    }
    else return false;
      bool leftAns = isBalanced(root->left);
     bool rightAns = isBalanced(root->right);
        return leftAns && rightAns;

  
}
pair<bool , int> isBalancedBetter(BinaryTreeNode<int>* root){
    if(root==NULL)
    {
        pair<bool,int> p ; 
        p.first = true ; 
        p.second = 0 ; 
        return p ;
    }
        pair<bool , int> leftAns = isBalancedBetter(root->left);
        pair<bool , int> rightAns = isBalancedBetter(root->right);
        pair<bool , int> Ans ; 
        if(leftAns.first == false || rightAns.first ==false){
            Ans.first = false ; 
            Ans.second = max(leftAns.second , rightAns.second) + 1 ; 
            return Ans ;   
        }
        else{
               if(leftAns.second - rightAns.second <= 1 ){
                   Ans.first = true ; 
                  Ans.second = max(leftAns.second , rightAns.second) + 1 ;
                  return Ans;
               }
               else{
                   Ans.first = false ; 
                   Ans.second = max(leftAns.second , rightAns.second) + 1 ;
                   return Ans ; 
               }
        }
}
void printTreeLevelWise2(BinaryTreeNode<int> *root)  ///  PRINT INPUT LEVELWISE
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (pendingNodes.size() != 0)
    {   
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front!=NULL){
            cout << front->data<<" ";
            
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }
        if (front->right!=NULL)
        {
            pendingNodes.push(front->right);
        }
        }
        else{
            if(pendingNodes.size() == 0 ){
                break;
            }
            cout<<"\n";
            pendingNodes.push(NULL);
            
        }
    }
}
BinaryTreeNode<int>* removeLeaf(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left ==NULL && root->right==NULL){
          return NULL;
    }
    BinaryTreeNode<int>* left = removeLeaf(root->left);
     BinaryTreeNode<int>* right = removeLeaf(root->right);
     root->left = left ;
     root->right = right;
     return root;
}
vector<Node<int>*> levelwiseList(BinaryTreeNode<int> *root)  ///  PRINT INPUT LEVELWISE
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    vector<Node<int>*> ans; 
    while (pendingNodes.size() != 0)
    {   
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front!=NULL){
          Node<int>* n = new Node<int>(front->data);
          if(head ==NULL){
            head = n ; 
            tail = n;
            ans.push_back(head);
          }
          else{
                tail->next = n ; 
                tail = tail->next;
          }
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }
        if (front->right!=NULL)
        {
            pendingNodes.push(front->right);
        }
        }
        else{
            tail->next = NULL;
            if(pendingNodes.size() == 0 ){
                break;
            }
            pendingNodes.push(NULL);
            head = NULL;
            tail = NULL;
            
        }
    }
    return ans;
}
void print(Node<int>*head)
{
    Node<int>*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
void zigzagTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return; 
    }
    stack<BinaryTreeNode<int>*> s1 ; 
    stack<BinaryTreeNode<int>*> s2 ;
    s1.push(root);
    while(!s1.empty())
    {
        while(!s1.empty())
        { BinaryTreeNode<int> * top=s1.top();
        s1.pop();
        cout<<top->data<<" ";
        
        if(top->left)
            s2.push(top->left);
       if(top->right)
            s2.push(top->right);
        }
        
        cout<<endl;
        
        while(!s2.empty())
        {
            BinaryTreeNode<int> * top=s2.top();
        s2.pop();
        cout<<top->data<<" ";
            
        if(top->right)
            s1.push(top->right);
        if(top->left)
            s1.push(top->left);
       
        }
        cout<<endl;   
    }
}
void nodesWithoutSibling(BinaryTreeNode<int>* root){
if(root==NULL)
        return;
    
    if(root->left && !root->right)
    {  cout<<root->left->data<<" ";
    
       nodesWithoutSibling(root->left); 
    }
     else if(!root->left && root->right)
    {  cout<<root->right->data<<" ";
    
       nodesWithoutSibling(root->right); 
    }
	else 
    {
        nodesWithoutSibling(root->left); 
        nodesWithoutSibling(root->right); 
    }
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
   nodesWithoutSibling(root);
}