#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {

        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(node *root)
{

    // base case;

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void preorder(node *root)
{

    // base case;

    if (root == NULL)
        return;

    cout << root->data << endl;
    preorder(root->left);

    preorder(root->right);
}

void postorder(node *root)
{

    // base case;

    if (root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);
    cout << root->data << endl;
}

int main()
{
    node *root = NULL;

    cout << "Enter the data : " << endl;

    inorder(root);

    return 0;
}