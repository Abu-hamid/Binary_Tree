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

node *solve(node *root, int k, int node)
{

    // base case;

    if (root == NULL)
        return NULL;

    if (root->data == NULL)
    {
        return root;
    }

    node *leftAns = solve(root->left, k, node);
    node *rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {

        k--;

        if (k <= 0)
        {
            // ans lock condition;
            k = INT_MAX; // during k-- never reach to the  zero;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {

        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(node *root, int k, int node)
{
    node *ans = solve(root, k, node);

    if (ans == NULL || ans->data == node)
        return -1;

    else
        return ans->data;
}

int main()
{

    return 0;
}