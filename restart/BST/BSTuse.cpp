#include <iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<stack>
#include"Node.h"
#include<utility>
#include<vector>
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
bool Search(BinaryTreeNode<int>* root , int k ){   //// SEARCH K 
        if(root==NULL){
            return false;
        }
        bool leftAns ; 
        bool rightAns ; 
        if( k == root->data){
            return true;
        }
        else if(k > root->data){
            leftAns = Search(root->right , k );
        }
        else{
            rightAns = Search(root->left , k);
        }
        return leftAns && rightAns;

}
void printInRange(BinaryTreeNode<int>* root , int k1 , int k2){   //// PRINT IN RANGE

        if(root==NULL){
            return ; 
        }
         if(root->data >=k1 && root->data<=k2){
            printInRange(root->left,k1,k2);
             cout<<root->data<<" ";
            printInRange(root->right,k1,k2);
         }
        if(root->data < k1 ){
            printInRange(root->right ,k1,k2);
        }
        else if(root->data > k2){
            printInRange(root->left,k1,k2);
        }
}
class isBSTReturn{
    public :
    bool isBST;
    int minimum;
    int maximum;
};
isBSTReturn isBST(BinaryTreeNode<int>* root){   //// TIME COMPLEXITY IMPROVED FROM RECURISON
    if(root==NULL){
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT16_MAX;
        output.maximum = INT16_MIN;
        return output;
    }
    isBSTReturn leftOutput = isBST(root->left);
    isBSTReturn rightOutput = isBST(root->right);
    int minimum = min(root->data , min(leftOutput.minimum , rightOutput.maximum));
    int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data<=rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST ;  
        isBSTReturn output;
        output.isBST = isBSTFinal;
        output.maximum = maximum;
        output.minimum = minimum;
        return output; 
}
bool isBST3(BinaryTreeNode<int>* root , int min = INT16_MIN,int max = INT16_MAX){  ///   SPACE COMPLEXITY IMPROVED
    if(root==NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool isLeftOK = isBST3(root->left , min , root->data-1);
    bool isRightOK = isBST3(root->right , root->data,max);
    return isLeftOK && isRightOK;

}
BinaryTreeNode<int>* constructFromArray(int arr[] ,int st , int end ){
        if(st>end){
            return NULL;
        }
        int mid = (st + end)/2 ;
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
        BinaryTreeNode<int>* leftAns = constructFromArray(arr , st , mid-1 );
        BinaryTreeNode<int>* rightAns = constructFromArray(arr , mid+1 , end );
        root->left = leftAns;
        root->right = rightAns;
        return root;
}
pair<Node*,Node*> BSTtoSortedLL(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<Node*,Node* > ans;
        ans.first = NULL;
        ans.second = NULL ;
        return ans;
    }
    Node* mid = new Node(root->data);
    pair<Node*,Node*> left = BSTtoSortedLL(root->left);
    pair<Node*,Node*> right = BSTtoSortedLL(root->right);
    pair<Node*,Node*> ans;
     if(left.first ==NULL && right.first ==NULL)
    {
        
        ans.first=mid;
        ans.second=mid;
       
    }
   else if(!left.first  && right.first )
   		 { ans.first=mid;
           mid->next=right.first;
   		     
        	ans.second=right.second;
  		  }
  else if(left.first && right.first==NULL)
  		  { ans.first=left.first;
      			left.second->next=mid;
  		        ans.second=mid;
               
  		  }
    else
    {
        ans.first=left.first;
        left.second->next=mid;
        mid->next=right.first;
        ans.second=right.second;
    }
    return ans ;
    
}
void Zigzag(BinaryTreeNode<int> * root)
{
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s1 ; 
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    while(!s1.empty()){
        BinaryTreeNode<int>* top = s1.top();
         s1.pop();
        cout<<top->data<<" ";
        if(top->left!=NULL){
            s2.push(top->left);
        }
        if(top->right!=NULL){
            s2.push(top->right);
        }
        cout<<endl;
    while(!s2.empty()){
            BinaryTreeNode<int>* top = s2.top();
            s2.pop();
        cout<<top->data<<" ";
        if(top->right!=NULL){
            s1.push(top->right);
        }
        if(top->left!=NULL){
            s1.push(top->left);
        }
    }
}
}
void inorder(vector<int> ans , BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inorder(ans,root->left);
    ans.push_back(root->data);
    inorder(ans,root->right);
}
void preorder(vector<int>  ans ,  BinaryTreeNode<int>* root , int *i){
    if(root==NULL){
        return; 
    }
    root->data = ans[++(*i)];
    cout<<root->data<<" ";
    preorder(ans,root->left , i);
    preorder(ans,root->right ,i);

}
void BSTtoMinHeap(BinaryTreeNode<int>* root){
    vector<int> ans;
    inorder(ans , root);
    int i = 0 ; 
    preorder(ans , root , &i);
}
int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    BSTtoMinHeap(root);
}