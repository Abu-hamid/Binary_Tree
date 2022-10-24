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

void inorder(node *root, int count)
{

    // base case;

    if (root == NULL)
        return;

    inorder(root->left, count);

    // condition for the leaf node;

    if (root->left == NULL && root->right == NULL)
    {

        count++;
    }

    inorder(root->right, count);
}

int NumOfLeaf(node *root)
{

    int count = 0;

    inorder(root, count);
    return count;
}
int main()
{

    return 0;
}