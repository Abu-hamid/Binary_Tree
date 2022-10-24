#include<iostream>
using namespace std;

class node{

    public:

    int data;
    node*left;
    node*right;

    node(int d){

        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }



};

node*buildTree(node*root){

    cout<<"Enter the data :"<<endl;

    int data;
    cin>> data;
    root = new node(data);

    if(data == -1)
    return NULL;

cout<<"Enter the data for left Insertion :"<<data<<endl;

root->left = buildTree(root->left);

cout<<"Enter the data for right Insertion :"<< data<< endl;

root->right = buildTree(root->right);

return root;


}

int main(){

node*root = NULL;

// create tree;
root = buildTree(root);

cout<< root->data;

return 0;
}