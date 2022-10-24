#include <iostream>
#include <queue>
#include <vector>
#include <ordered_map>

using namespace std;


// ***** MOst important question;

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

vector<int> VerticalOrder(node *root)
{

    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
        return ans;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {

        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;

        int hrz = temp.second.first;
        int lvl = temp.second.second;

        nodes[hrz][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hrz - 1, lvl + 1)));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hrz + 1, lvl + 1)));
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {

                ans.push_back(k);
            }
        }
    }

    return ans;
}
int main()
{

    return 0;
}