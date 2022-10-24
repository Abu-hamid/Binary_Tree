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

vector<int> ZigZagTraverse(node *root)
{

    vector<int> result;

    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);

        // level process;

        for (int i = 0; i < size; i++)
        {

            node *frontnode = q.front();
            q.pop();

            // nprmal insert or reverse insert;
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontnode->data;

            if (frontnode->left)
                q.push(frontnode->left);

            if (frontnode->right)
                q.push(frontnode->right);
        }

        // direction change ;

        leftToRight != leftToRight;

        // copy the data of temp arr into the result 
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{

    return 0;
}