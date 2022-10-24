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


// T.c O(n^2) and S.c O(n);

int findposition(int in[] , int element , int n){

    for(int i=0;i<n;i++){

        if(in[i] == element)
        return i;

        else
        return -1;
    }
}

node* solve(int in[] , int pre[] , int &index , int inOrderStart , int inOrderEnd , int n){

    // base case;
    if(index >= n || inOrderStart > inOrderEnd)
    return NULL;

    // create root node from the inorder array;
    int element = pre[index];
    index++;
    node*root = new node(element);

    // find the pos of the root in inorder;
    int pos = findposition(in , element , n);

    // recursive calls ;

    root->left = solve(in , pre , index , inOrderStart , pos - 1, n);
    root->right = solve(in , pre , index , pos + 1 , inOrderEnd , n);

    return root;
}



node*BuildTree(int in[] , int pre[] , int n){

    int preOrderIndex = 0;

     node *ans = solve(in , pre , preOrderIndex , 0 , n-1 , n);
     return ans;
}


/*

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{

    for (int i = 0; i < n; i++)
    {

        nodeToIndex[in[i]] = i;
    }
}

node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{

    // base case;
    if (index >= n || inOrderStart > inOrderEnd)
        return NULL;

    // create root node from the inorder array;
    int element = pre[index];
    index++;
    node *root = new node(element);

    // find the pos of the root in inorder;
    int pos = nodeToIndex[element];

    // recursive calls ;
    
    root->left = solve(in, pre, index, inOrderStart, pos - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, pos + 1, inOrderEnd, n, nodeToIndex);

    return root;
}

node *buildTree(int in[], int post[], int n)
{

    int preOrderIndex = 0;
    map<int, int> nodeToIndex;

    createMapping(in, nodeToIndex, n);

    node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

*/


int main(){

return 0;
}