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

// time complecity is so high as O(n^2);


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

bool isBalanced(node *root)
{

    // base case;

    if (root == NULL)
        return true;

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    bool diff = abs(HeightOfBT(root->left) - HeightOfBT(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {

        return false;
    }
}

*/

// time complexity O(n);

pair<bool, int> isBalancedFast(node *root)
{

    // base case;

    if (root == NULL)
    {

        pair<bool, int> p = make_pair(true, 0);// first part is for the left and right bool value or ture /false; and second part is the height of the tree; 

        return p;
    }

    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isBalanced(node *root)
{

    return isBalancedFast(root).first;
}
int main()
{

    return 0;
}