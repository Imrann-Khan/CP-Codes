#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, level;
    Node *left, *right, *parent;

    Node(int v)
    {
        key=v;
        left=NULL;
        right=NULL;
        parent =NULL;

    }
};


class BST{
public:
    Node *root;

    BST()
    {
        root=NULL;
    }
    void insert(int val){
        Node *newNode= new Node(val);
        if(root==NULL)
        {
            root =newNode;
            return;
        }
        Node *temp=root;
        Node *prev=NULL;
        while(temp!=NULL)
        {
            prev=temp;
            if(val<temp->key)
                temp=temp->left;
            else temp=temp->right;
        }
        if(val < prev->key)  prev->left=newNode;
        else prev->right=newNode;
        newNode->parent=prev;
    }

    Node* findNode(int val){
        Node *temp=root;
        while(temp!=NULL)
        {
            if(temp->key > val)
                temp=temp->right;
            else if(temp->key < val)
                temp=temp->left;
            else if(temp->key == val)
                return temp;
        }
        return temp;
    }

    Node* findMaximum(Node *node){
        if(node->right == NULL)
            return node;
        return findMaximum(node->right);
    }

    Node* findMinimum(Node *node){
        if(node->right == NULL)
            return node;
        return findMinimum(node->left);

    }

    void inOrder(Node *node){
        if(node== NULL) return;
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

private:
    Node* findSuccessor(Node *node){
        return findMinimum(node->right);
    }

    void delete0Child(Node *node){
        if(node == root)
        {
            delete node;
            root=NULL;
            return;
        }
        Node *par=node->parent;
        if(node->key < par->key)
        {
            par->left=NULL;
        }
        else
        {
            par->right=NULL;
        }
        delete node;
    }

    void delete1Child(Node *node){
        if(node==root)
        {
            Node *child=node->left;
            if(child==NULL)
            {
                child=node->right;
            }

            root =child;
            root->parent==NULL;
            delete node;
            return;
        }
        Node *par=node->parent;
        Node *child=node->left;
        if(child==NULL)
        {
            child=node->right;
        }
        if(node->key < par->key)
        {
            par->left=child;
        }
        else
        {
            par->right=child;

        }
        delete node;
    }

    void delete2Child(Node *node){
        Node *ios=findSuccessor(node);
        node->key=ios->key;

        if(ios->right==NULL)
            delete0Child(ios);
        else delete1Child(ios);
    }

public:
    bool deleteNode(int val){
        Node *temp=findNode(val);
        if(temp==NULL)
            return false;
        if(temp->left==NULL && temp->right==NULL)
        {
            delete0Child(temp);
        }
        else if(temp->left==NULL || temp->right==NULL)
            delete1Child(temp);
        else
            delete2Child(temp);
    }

    int height(Node *node){
        ///returns the height of the bst
        ///Must develop a recursive solution
    }


    void bfs(){
        queue<Node*> q;
        root->level = 0;
        int level = root->level;
        q.push(root);

        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            if(temp->level > level){
                cout<<endl;
                level++;
            }
            cout<<temp->key<<" ";
            if(temp->left!=NULL){
                if(temp->left!=root)  temp->left->level = temp->level + 1;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                if(temp->right!=root)  temp->right->level = temp->level + 1;
                q.push(temp->right);
            }
        }
    }
};

int main(){
    BST b;

    while(1){
        cout<<"1. Insert    2. Sort      3. Level Order    4. Minimum\n5. Maximum   6. Delete    7. Height         8. End\n\n";
        int x;
        cin>>x;

        if(x==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            b.insert(y);
            cout<<y<<" is inserted in the tree"<<endl;
        }

        else if(x==2){
            cout<<"Sorted List of the tree: ";
            b.inOrder(b.root);
            cout<<endl;
        }

        else if(x==3){
            if(b.root==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Level Wise Traversal of the tree:"<<endl;
            b.bfs();
            cout<<endl;
        }

        else if(x==4){
            if(b.root==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Minimum of the tree: ";
            Node *min = b.findMinimum(b.root);
            cout<<min->key<<endl;
        }

        else if(x==5){
            if(b.root==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Maximum of the tree: ";
            Node *max = b.findMaximum(b.root);
            cout<<max->key<<endl;
        }

        else if(x==6){
            if(b.root==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Delete Value: ";
            int y;
            cin>>y;
            bool test = b.deleteNode(y);
            if(test)   cout<<y<<" is deleted from the tree"<<endl;
            else    cout<<y<<" is not found in the tree"<<endl;
        }
        else if(x==7){
            if(b.root==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Height of the tree: "<<b.height(b.root)<<endl;
        }
        else if(x==8){
            break;
        }
        else{
            cout<<"Invalid Choice"<<endl;
        }
        cout<<endl;
    }
    return 0;
}




