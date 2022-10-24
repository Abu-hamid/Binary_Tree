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

int HeightOfTree(node *root)
{

    // base case
    if (root == NULL)
        return 0;

    int left = HeightOfTree(root->left);
    int right = HeightOfTree(root->right);

    int ans = max(left, right) + 1;

    return ans;
}
int main()
{

    return 0;
}