#include <iostream>
#include <ordered_map>
#include <vector>
#include <queue>
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

node *createParentMapping(node *root, int target, map<node *, node *> &nodeToparent)
{

    node *res = NULL;
    queue<node *> q;
    q.push(root);
    nodeToparent[root] = NULL;

    while (!q.empty())
    {

        node *front = q.front();
        q.pop();

        if (front->data == target)
        {

            res = front;
        }

        if (front->left)
        {

            nodeToparent[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {
            nodeToparent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int  burnTree(node *root, map<node *, node *> &nodeToparent)
{

    map<node *, bool> visited;
    queue<node *> q;

    q.push(root);
    visited[root] = true;

    int time = 0;

    while (!q.empty())
    {
        bool flag = true;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {

            // process the neighbouring node;

            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (nodeToparent[front] && !visited[nodeToparent[front]])
            {
                flag = true;
                q.push(nodeToparent[front]);
                visited[nodeToparent[front]] = true;
            }
        }


        if(flage == true){
            time++;
        }
    }

    return time;
}

int mintime(node *root, int target)
{

// Algo;
// step 1:create nodeToparent mapping;
// step 2:find target node;
// step 3:burn the tree in min time;
    
    map<node *, node *> nodeToparent;
    node *targetNode = createParentMapping(root, target, nodeToparent);

    int ans = burnTree(targetNode, nodeToparent);

    return ans;
}

int main()
{

    return 0;
}