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

void MorrisTraversal(node *root)
{

    node *curr = root;

    if (root == NULL)
        return;

    while (curr != NULL)
    {

        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }

        else
        {

            node *pred = curr->left;

            // we find the inorder predecessor of the current node;
            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }

            // make curr as the right child of its; oR make the temporary link of the pred with the curr right;

            if (pred->right == NULL)
            {

                pred->right = curr;
                curr = curr->left;
            }

            // restore the original tree; OR removal of the temporary link fo the right child

            else
            {

                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{

    return 0;
}