#include <bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int value)
    {
        this->value=value;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int value, TreeNode* left, TreeNode* right)
    {
        this->value=value;
        this->left=left;
        this->right=right;
    }
};

bool Search(TreeNode *root, int val)
{
    if(root==nullptr) return false;
    if(root->value==val) return true; 
    if(val<root->value) return Search(root->left,val);
    if(val>root->value) return Search(root->right,val);
    return false;
}

TreeNode *Insert(TreeNode* root, int val)
{
    if(root==nullptr) return new TreeNode(val);
    if(val<root->value) root->left = Insert(root->left,val);
    if(val>=root->value) root->right = Insert(root->right,val);
    return root;
}
void printLevelOrder(TreeNode *root)
{
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        TreeNode *cur=q.front();
        q.pop();
        if(cur==NULL)
        {
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<cur->value<<" ";
        if(cur->left!=NULL) q.push(cur->left);
        if(cur->right!=NULL) q.push(cur->right);
    }
}

TreeNode* Succ(TreeNode* root)
{
    while(root->left!=nullptr)
        root=root->left;
    return root;
}

TreeNode* Delete(TreeNode* root, int val)
{
    if(root==nullptr) return root;
    if(val<root->value)
        root->left = Delete(root->left,val);
    else if(val>root->value)
        root->right = Delete(root->right,val);
    else
    {
        if(root->left==nullptr)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right==nullptr)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            TreeNode* succ = Succ(root->right);
            root->value = succ->value;
            root->right = Delete(root->right,succ->value);
        }
        return root;
    }
}

signed main()
{
    TreeNode *root=new TreeNode(15);
    root->left= new TreeNode(5);
    root->left->left= new TreeNode(3);
    root->right= new TreeNode(20);
    root->right->right= new TreeNode(80);
    root->right->left= new TreeNode(18);
    root->right->right->left= new TreeNode(16);

    //cout<<Search(root, 18)<<endl;
    printLevelOrder(root);
    Insert(root,100);
    cout<<endl;
    Delete(root, 20);
    cout<<endl;
    printLevelOrder(root);
}
