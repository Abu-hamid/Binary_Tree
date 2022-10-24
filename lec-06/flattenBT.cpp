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

void flattenBT(node *root)
{

    node *curr = root;

    while (curr != NULL)
    {

        if (curr->left)
        {

            node *pred = curr->left;// find predecessor; move one left and then move right till right not null;
            while (pred->right)
            {

                pred = pred->right;
            }

            pred->right = curr->right;// link the right and curr pointer to the corrct position;
            curr->right = curr->left;

            curr->left = NULL;
        }

        curr = curr->right;
    }
}
int main()
{

    return 0;
}