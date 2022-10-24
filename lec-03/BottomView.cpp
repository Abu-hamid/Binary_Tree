#include <iostream>
#include <queue>
#include <vector>
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

vector<int> TopView(node *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> topNode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hrzD = temp.second;

        // if one value is present of HRZD  then do nothing;

        topNode[hrzD] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hrzD - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hrzD + 1));
    }

    for (auto i : topNode)
    {

        ans.push_back(i.second);
    }

    return ans;
}
int main()
{

    return 0;
}