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

void *builfromLevelorder(node *&root)
{

    queue<node *> q;
    
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << "Enter the left data :" << temp->data << endl;

        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {

            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right data :" << temp->data << endl;

        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{

    return 0;
}