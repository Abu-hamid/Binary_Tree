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

pair<int, int>solve(node*root){

    // base case;

    if(root == NULL){

        pair<int ,int >p = make_pair(0,0);
        return p;
    }

    pair<int, int> left =solve(root->left);
    pair<int, int> right =solve(root->right);

    pair<int, int> res;

    // including the curr node of the tree;
    res.first = root->data + left.second + right.second;

    // excluding the curr node of the tree;
    res.second = max(left.first , left.second) + max(right.first , right.second);

    return res;

    
    
}

int getMaxSum(node*root){

    pair<int ,int>ans = solve(root);
    return max(ans.first , ans.second);
}

int main(){

return 0;
}