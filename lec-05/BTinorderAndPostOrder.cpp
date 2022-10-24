#include <iostream>
#include <ordered_map>
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

// T.c o(nlogn); S.c O(n);

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{

    for (int i = 0; i < n; i++)
    {

        nodeToIndex[in[i]] = i;
    }
}

node *solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{

    // base case;
    if (index < 0 || inOrderStart > inOrderEnd)
        return NULL;

    // create root node from the inorder array;
    int element = post[index];
    index++;
    node *root = new node(element);

    // find the pos of the root in inorder;
    int pos = nodeToIndex[element];

    // recursive calls ; in postorder and inorder we first make right sub tree otheer than left sub part;
    root->right = solve(in, post, index, pos + 1, inOrderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inOrderStart, pos - 1, n, nodeToIndex);

    return root;
}

node *buildTree(int in[], int post[], int n)
{

    int postOrderIndex = n - 1;
    map<int, int> nodeToIndex;

    createMapping(in, nodeToIndex, n);

    node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

int main()
{

    return 0;
}