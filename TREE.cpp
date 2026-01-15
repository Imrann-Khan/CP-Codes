#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


struct Node{
    ll value;
    Node *left;
    Node *right;
    Node(ll k)
    {
        value=k;
        left=right=NULL;
    }
};

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

void inOrder(Node *root)
{
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->value<<" ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if(root==NULL) return;
    cout<<root->value<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->value<<" ";
}

ll height(Node *root)
{
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}

void printLevelOrder(Node *root)
{
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *cur=q.front();
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

ll getSize(Node *root)
{
    if(root==NULL) return 0;
    return 1+getSize(root->left)+getSize(root->right);
}


void printKDistance(Node *root, ll k)
{
    if(root==NULL) return;
    if(k==0) cout<<root->value<<" ";
    else
    {
        printKDistance(root->left,k-1);
        printKDistance(root->right,k-1);
    }
}

ll getMax(Node *root)
{
    if(root==NULL) return INT_MIN;
    else return max(root->value,max(getMax(root->left),getMax(root->right)));
}

ll maxLevel=0;
void printLeftView(Node *root, ll level)
{
    if(root==NULL) return;
    else
    {
        if(maxLevel<level)
        {
            cout<<root->value<<" ";
            maxLevel=level;
        }
        printLeftView(root->left,level+1);
        printLeftView(root->right,level+1);
    }
}

bool isSum(Node *root)
{
    if(root==NULL) return true;
    if(root->left==NULL and root->right==NULL)  return true;
    ll sum=0;
    if(root->right!=NULL) sum+=root->right->value;
    if(root->left!=NULL) sum+=root->left->value;
    return (sum==root->value and isSum(root->left) and isSum(root->right));
}

bool findPath(Node *root, vector<Node*> &v, int n)
{
    if(root==NULL) return false;
    v.push_back(root);
    if(root->value==n) return true;
    if(findPath(root->left,v,n) || findPath(root->right,v,n)) return true;
    v.pop_back();
    return false;
}

// Node* LCA(Node *root, ll p, ll q) Naive
// {
//     vector<Node*> v1;
//     vector<Node*> v2;
//     findPath(root,v1,60);
//     findPath(root,v2,70);
//     for(ll i=0;i<v1.size() && v2.size();i++)
//     {
//         if(v1[i]==v2[i]) return v1[i];
//     }
//     return NULL;
// }

Node* LCA(Node *root, ll p, ll q) //Efficient
{
    if(root==NULL) return NULL;
    if(root->value==p or root->value==q) return root;
    Node *lca1=LCA(root->left,p,q);
    Node *lca2=LCA(root->right,p,q);
    if(lca1!=NULL and lca2!=NULL) return root;
    if(lca1!=NULL) return lca1;
    else return lca2;
}

signed main()
{
    fast
    Node *root=new Node(100);
    root->left= new Node(20);
    root->left->left= new Node(40);
    root->left->right= new Node(50);
    root->right= new Node(300);
    root->right->right= new Node(60);
    root->right->left= new Node(70);
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl<<height(root)<<endl;
    printLevelOrder(root);
    cout<<endl<<getSize(root)<<endl;
    printKDistance(root,2);
    cout<<getMax(root)<<endl;
    printLeftView(root,1);
    if(isSum(root)) cout<<"YES\n";
    else cout<<"NO\n";
    vector<Node*> v;
    cout<<LCA(root,60,70)->value;
}