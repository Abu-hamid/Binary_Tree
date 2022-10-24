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

void solve(node *root, int sum, int &maxSum, int len, int &maxlen)
{

    // base case;

    if (root == NULL)
    {

        if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }

        else if (len == maxlen)
        {

            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum = sum + root->data;

    solve(root->left , sum ,maxSum , len + 1 , maxlen);
    solve(root->right , sum ,maxSum , len + 1, maxlen);
}

int sumRootToLeaf(node *root)
{

    int len = 0;
    int maxlen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxlen);
    return maxSum;
}

int main()
{

    return 0;
}