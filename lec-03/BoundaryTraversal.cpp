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

void traverseLeftpart(node *root, vector<int> &ans)
{

    // base case;
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);

    if (root->left)
        traverseLeftpart(root->left, ans);

    else
        traverseLeftpart(root->right, ans);
}

void traverseLeaf(node *root, vector<int> &ans)
{

    // base case;
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {

        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRightpart(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)

        traverseRightpart(root->right, ans);

    else
        traverseRightpart(root->left, ans);

    // durin returning store the data of the root;

    ans.push_back(root->data);
}

vector<int> Boundary(node *root)
{

    vector<int> ans;

    if (root == NULL)
        return ans;
    ans.push_back(root->data);

    // lef part print;

    traverseLeftpart(root->left, ans);

    // traverse the leaf node;

    // left sub tree
    traverseLeaf(root->left, ans);

    // right sub tree;
    traverseLeaf(root->right, ans);

    // right part print;

    traverseRightpart(root, ans);

    return ans;
}

int main()
{

    return 0;
}