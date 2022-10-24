#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {

        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);

    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();

        q.pop();

        if(temp == NULL)

        // prev complete traversed;

        cout<<endl;

        if(!q.empty())

        q.push(NULL);


        else{

            cout<< temp->data << endl;

            cout<< temp->data<<" ";

        if (temp->left)

            q.push(temp->left);

        if (temp->right)

            q.push(temp->right);

        }
    }
}

int main()
{

    return 0;
}