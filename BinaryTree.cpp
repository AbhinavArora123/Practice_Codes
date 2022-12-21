#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter node data:" <<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data to the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data to the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

//level order traversal

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrder(node* root){
    stack<node*> s;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        root=q.front();
        q.pop();
        s.push(root);

        if(root->left){
            q.push(root->left);
        }
        if(root->right){
            q.push(root->right);
        }
    }
    while(!s.empty()){
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildUsingLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter root data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while (!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"Enter left data of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right data of: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
    
}


int main(){
    node* root=NULL;

    buildUsingLevelOrder(root);
    levelOrderTraversal(root);
    // root=buildTree(root);

    // cout<<"Reverse Level order traversal is:" <<endl;
    // levelOrderTraversal(root);
    // reverseLevelOrder(root);

    // cout<<"postorder traversal is: "<<endl;
    // postorder(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 