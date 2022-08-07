#include <iostream>
#include <queue>
#include "Treenode.h"
#include <algorithm>
#include <utility>
using namespace std;
void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
    return;
}

TreeNode<int> *takeInputLevelWise()
{

    int rootData;
    cout << "Enter the root data";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of" << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "Enter" << i << "the child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
int numNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}
int sumNodes(TreeNode<int> *root)
{

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumNodes(root->children[i]);
    }
    return sum;
}
TreeNode<int> *maxNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    TreeNode<int> *x = root;
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
            if (x->data < front->children[i]->data)
            {
                x = front->children[i];
            }
        }
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
        }
    }
    return x;
}

int height(TreeNode<int> *root)
{ //// HEIGHT OF A TREE
    int ht = 0;
    if (root == NULL)
    {
        return 0;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int ch = height(root->children[i]);
        ht = std::max(ch, ht);
    }
    ht += 1;
    return ht;
}
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}
int leafNodes(TreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += leafNodes(root->children[i]);
    }
    return ans;
}
void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}
// DELETE A TREE AS Tree is dynamically created
void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}
int countNodes(TreeNode<int> *root, int x)
{
    int count = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->data > x)
    {
        count++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i], x);
    }
    return count;
}
pair<TreeNode<int> *, int> nodeWithMaxChild(TreeNode<int> *root)
{
    if(root->children.size()==0){
        pair<TreeNode<int> *, int> baseCase ; 
        baseCase.first = root ; 
        baseCase.second = root->data ; 
        return baseCase;
    }
    pair<TreeNode<int> *, int> work;
    work.first = root;
    work.second = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        work.second += root->children[i]->data;
    }
  pair<TreeNode<int> *, int> recursion ;
    for (int i = 0; i < root->children.size(); i++)
    {
         recursion = nodeWithMaxChild(root->children[i]);
          if (work.second < recursion.second)
    {
        work = recursion;
    }
    }
    return work;
}
TreeNode<int> *nodeWithMaxChildHelper(pair<TreeNode<int> *, int> nodeWithMaxChild)
{
         
    return nodeWithMaxChild.first;
}
bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1->data != root2->data)
        return false;
    
    if(root1->children.size() != root2->children.size())
        return false;
    
    bool ans =true;
    for(int i=0;i<root1->children.size();i++)
    {
        bool smallans = isIdentical(root1->children[i],root2->children[i]);
        if(smallans == false)
        {   ans=smallans;
            return ans;
        }
    }
    return ans;
}
TreeNode<int>* nextLarger(TreeNode<int>* root , int x){
        if(root==NULL)
        {
            return NULL ; 
        }
        TreeNode<int>* ans ; 
        if(root->data > x){
            ans = root ;
        }
        else {
            ans = NULL;
        }
        for(int i = 0 ; i < root->children.size(); i++){
                TreeNode<int>* smallSum = nextLarger(root->children[i] , x );
                if(ans == NULL){
                    ans = smallSum;
                }
                if(smallSum->data < ans->data){
                    ans = smallSum;
                }
        }
return ans; 
}
void replaceWithDepth(TreeNode<int>* root , int depth)
{   
    root->data = depth ; 
    for(int i = 0 ; i < root->children.size(); i++){
        replaceWithDepth(root->children[i] , depth + 1) ;
    }

}
pair<TreeNode<int>* , TreeNode<int>*> secondLargestElement(TreeNode<int>* root){
    pair<TreeNode<int>* , TreeNode<int>*> ans ;
    ans.first = root;
    ans.second = NULL ; 
    for(int i = 0 ; i < root->children.size(); i++){
        pair<TreeNode<int>* , TreeNode<int>*> temp = secondLargestElement(root->children[i]);       
       if(temp.first->data > ans.first->data){
           if(temp.second ==NULL){
               ans.second = ans.first ;
               ans.first = temp.first;
           }
           else if(temp.second->data > ans.first->data){
               ans.second = temp.second;
               ans.first = temp.first;
           }
           else{
                    ans.second = ans.first;
                    ans.first = temp.first ; 
           }
           }
        else{
            if(ans.first->data != temp.first->data && (ans.second ==NULL || ans.second->data < temp.first->data)){
                ans.second = temp.first; 
            }

        }
           }
           return ans ; 
    }
     
     

// 10 3 20 30 40 2 40 50 0 0 0 0
int main()
{

    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    pair<TreeNode<int>* , TreeNode<int>*> ans =  secondLargestElement(root);
    cout<<ans.second->data<<endl ;
  
}