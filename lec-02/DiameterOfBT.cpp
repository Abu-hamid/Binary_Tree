#include <iostream>
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

/*

// time comp,excity is o(n^2);


int HeightOfBT(node *root)
{

    // base case
    if (root == NULL)
        return 0;

    int left = HeightOfBT(root->left);
    int right = HeightOfBT(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

int DiameterOfBT(node *root)
{

    // base case;

    if (root == NULL)
        return 0;

    int op1 = DiameterOfBT(root->left);
    int op2 = DiameterOfBT(root->right);

    int op3 = HeightOfBT(root->left) + HeightOfBT(root->right) + 1;

    int ans = max(op1, max(op2, op3));

    return ans;
}


*/

pair<int, int> DiameterFast(node *root)
{

    // base case

    if (root == NULL)
    {
        pair<int, int> P = make_pair(0, 0); // first value is Diameter and second value is the height;

        return P;
    }

    pair<int, int> left = DiameterFast(root->left);
    pair<int, int> right = DiameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));             // this is for the diameter of the tree;
    ans.second = max(left.second, right.second) + 1; // this is the height of the tree ;

    return ans;
}

int DiameterOfBT(node *root)
{

    return DiameterFast(root).first;
}

int main()
{

    return 0;
}