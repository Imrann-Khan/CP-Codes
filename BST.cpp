#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, level;
    Node *left, *right, *parent;
};


class BST{
public:
    Node *root;

    void insert(int val){

    }

    Node* findNode(int val){

    }

    Node* findMaximum(Node *node){

    }

    Node* findMinimum(Node *node){

    }

    void inOrder(Node *node){

    }

private:
    Node* findSuccessor(Node *node){

    }

    void delete0Child(Node *node){

    }

    void delete1Child(Node *node){

    }

    void delete2Child(Node *node){

    }

public:
    bool deleteNode(int val){

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
}

/*
1
44

1
17

1
88

1
32

1
65

1
97

1
28

1
54

1
82

1
29

1
76

1
80
*/



