#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *LCA(node *root, int n1, int n2)
{

    // base case;

    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == NULL)
        return root;

    node *leftAns = LCA(root->left, n1, n2);
    node *rightAns = LCA(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
        return root;

    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;

    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;

    else
        return NULL;
}

int main()
{

    return 0;
}