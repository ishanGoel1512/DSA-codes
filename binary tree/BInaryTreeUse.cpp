#include<iostream>
using namespace std;
#include <queue>
#include "binary_tree.h"
void postorder(BinaryTreeNode<int>* root)   //// / TRAVERSALS
{
    if(root==NULL)
    {
        return ; 
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;

}
void preorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return ; 
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void inorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return ; 
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void printMirror(BinaryTreeNode<int> * root) /// MIRROR TREE 
{     if(root->data==-1)
{
    return ;
}
     queue<BinaryTreeNode<int>*> pending;
     pending.push(root);
     
    while(pending.size()!=0)
    {  
        cout<<pending.front()->data<<":";
        BinaryTreeNode<int>* front = pending.front();
        pending.pop();
        if(front->left!=NULL)
        {
            cout<<" L:"<<front->right->data;
            pending.push(front->right);
        }
        if(front->right!=NULL)
        {
            cout<<" R:"<<front->left->data;
            pending.push(front->left);
        }
        cout<<endl;

    }


}
int height(BinaryTreeNode<int>* root)   /////   HEIGHT 
{  
    if (root == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = height(root->left);
        int rDepth = height(root->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
     
    
}
bool findx(BinaryTreeNode<int>* root ,int x )  ///  x node present
{    if(root==NULL)
   {
    return 0 ;
   }
    if(x==root->data)
    {
        return 1 ;
    }
    
    bool x1 = findx(root->left,x);
    bool x2 = findx(root->right,x);
    return x1 + x2 ;
}
/*int countNodes(BinaryTreeNode<int> * root)  ////   COUNT NODES
{
    
    if(root==NULL)
    (
        return 0 ; 

    )

    return 1+ countNodes(root->left)+ countNodes(root->right);
}*/
void printLevelWise(BinaryTreeNode<int> * root)        /////LEVEL WISE PRINTING
{     if(root->data==-1)
{
    return ;
}
     queue<BinaryTreeNode<int>*> pending;
     pending.push(root);
     
    while(pending.size()!=0)
    {  
        cout<<pending.front()->data<<":";
        BinaryTreeNode<int>* front = pending.front();
        pending.pop();
        if(front->left!=NULL)
        {
            cout<<" L:"<<front->left->data;
            pending.push(front->left);
        }
        if(front->right!=NULL)
        {
            cout<<" R:"<<front->right->data;
            pending.push(front->right);
        }
        cout<<endl;

    }


}
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
BinaryTreeNode<int>* takeinput()     // NORMAL INPUT
{ 

    int rootData ; 
    cout<<"Enter data" << endl;
    cin>>rootData;
if(rootData==-1)
{
    return NULL ;
}
BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
BinaryTreeNode<int> *LeftChild = takeinput();
BinaryTreeNode<int> *RightChild = takeinput();
root->left = LeftChild;
root->right = RightChild;
return root ;
}
void printBinaryTree(BinaryTreeNode<int> * root)
{
    if (root==NULL)
    {
        return ;
    }
    cout<<root->data<<":";
    if (root->left != NULL)
    {
        cout<<"L"<<root->left->data;
    }
    if(root->right !=NULL )
    {
        cout<<"R"<<root->right->data ;
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
BinaryTreeNode<int>* buildTreehelper(int* in , int *pre , int InS , int InE , int PreS , int PreE)
{
if(InS>InE)
{
    return NULL ; 
}
int rootData = pre[PreS];
int rootIndex = -1 ; 
for(int i=InS ; i<=InE ; i++)
{
    if(in[i]==rootData)
    {
        rootIndex = i ;
        break; 
    }
    
}
int lpres = PreS + 1;
int lins = InS;
int line = rootIndex - 1 ;
int lpree = line - lins + lpres;
int rpres = lpree + 1  ;
int rpree = PreE;
int rins = rootIndex + 1 ;
int rine = InE;
BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
root->left = buildTreehelper(in, pre , lins,line,lpres,lpree);
root->right = buildTreehelper(in , pre , rins , rine,rpres, rpree);
return root ;
}

BinaryTreeNode<int> * buildPostTree(int* in , int * pos , int inS , int inE , int posS , int posE)
 {                               ////////  BUILD TREE FROM PSOT ORDER AND INORDER
    if (inS>inE)
    {  return NULL ;

    }
    int rootData = pos[posE];
    int rootIndex = -1 ;
    for(int i= inS ; i<=inE;i++){
        if(in[i]==rootData)
        {
            rootIndex = i ;
            break;
        }
    }
        int lposs=posS;
        int lins = inS;
        int line = rootIndex - 1;
        int lpose= line - lins + lposs;
        int rposs =lpose + 1 ;
        int rpose = posE -1  ;
        int rins = rootIndex + 1 ;
        int rine = inE;
        BinaryTreeNode<int> * root = new  BinaryTreeNode<int>(rootData);
        root->left = buildPostTree(in,pos,lins,line,lposs,lpose);
        root->right = buildPostTree(in,pos,rins,rine,rposs,rpose);
        return root ; 
    
}  
BinaryTreeNode<int>* buildTree(int* in , int* pos , int size )    /////    BUILD TREE USING INORDER AND PREORDER
     {
         return buildPostTree(in , pos , 0 , size-1 , 0 , size-1);
     }   
pair<int,int> heightDiameter(BinaryTreeNode<int> * root)  //////  HEIGHT & DIAMETER OF A BINARY TREE 
{
    if(root==NULL)
    {
        pair<int,int> p ;
        p.first=0;
        p.second = 0;
        return p ;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second; 
    int rh = rightAns.first;
    int rd = rightAns.second;
    int height = 1 + max(lh,rh);
    int diameter = max(lh +rh ,max(ld , rd ));
    pair<int,int> p ;
    p.first = height ;
    p.second = diameter ; 
    return p ; 
}    
pair<int,int> MaxNMin(BinaryTreeNode<int>* root )
{
    if(root==NULL)
    {
        pair<int,int> p; 
        p.first=1;
        p.second =1; 
        return p; 
    }
   
    if(root->left==NULL && root->right==NULL)
    {
        pair<int,int> p; 
        p.first = root->data ;
        p.second = root->data ;
        return p ; 
    }
    pair<int,int> leftAns = MaxNMin(root->left);
    pair<int,int> rightAns = MaxNMin(root->right);
    int lm = leftAns.first;
    int lmn = leftAns.second ; 
    int rm = rightAns.first; 
    int rmn = rightAns.second ; 
    int maximum = max(root->data,max(lm,rm));
    int minimum = min(root->data,min(lmn , rmn));
    pair<int,int> p ;
    p.first = maximum ;
    p.second = minimum ; 
    return p;
} 
int sumNodes(BinaryTreeNode<int>* root)  //// SUM OF ALL THE NODES
{
    int sum = 0 ;
    if(root == NULL )
    {     
        return 0;
    }
    
    int leftAns = sumNodes(root->left);
    int rightAns = sumNodes(root->right);
    return root->data + leftAns +rightAns ;


}
bool balancedData(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0 ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 0 ; 
    }
    if(((root->left->data - root->right->data)==1)  || ((root->right->data - root->left->data)==1))
    {
        return 1 ;
    }
    bool leftAns = balancedData(root->left);
    bool rightAns = balancedData(root->right);
    return leftAns == rightAns ;
}
pair<int,bool> isBalanced(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,bool> p;
        p.first = 0 ; 
        p.second = 1 ;
        return p ;
    }
    pair<int,bool> a = isBalanced(root->left);
    pair<int,bool> b = isBalanced(root->right);
    int height = 1 + max(a.first, b.first);
    
    if(a.first - b.first == 1 || a.first - b.first == -1)
    { 
        pair<bool,bool> p ;
        p.second = 1 ;
        return p;
    } 
    pair<int,bool> p ; 
    p.first = height ;
    p.second = a.second && b.second; 
    return p ;

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
BinaryTreeNode<int>* removeLeaf(BinaryTreeNode<int>* root)   /////LEAF NODES DELETE
{
    if(root==NULL)
    {
        return NULL ;

    }
    if(root->left==NULL && root->right==NULL)
{    
    
    delete root;
    return NULL;
}
root->left = removeLeaf(root->left);
root->right = removeLeaf(root->right);
return root;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 
int main()
{

/*BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
BinaryTreeNode<int> * node1 = new BinaryTreeNode<int>(2);
BinaryTreeNode<int> * node2 = new BinaryTreeNode<int>(3);
root->left = node1;
root->right = node2;
*/


BinaryTreeNode<int>* root =takeInputLevelWise();
BinaryTreeNode<int>* root1 = removeLeaf(root);
LevelWiseprint(root1);

/*pair<int,int> p = MaxNMin(root);
cout<<"Maximum = "<<p.first<<endl; 
cout<<"Minimum = "<<p.second<<endl;  */


/*
int in[]= {4,2,5,1,6,3,7};
int pos[] = {4,5,2,6,7,3,1};
BinaryTreeNode<int>* root = buildTree(in,pos,7);
printBinaryTree(root);
*/

}