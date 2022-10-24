#include<iostream>
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


bool isIdentical(node*r1 , node*r2){

    // base case;

    if(r1 == NULL && r2 == NULL){
        return true;
    }

    if((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL)){

        return false;
    }

    bool left = isIdentical(r1->left , r2->left);
    bool right = isIdentical(r1->right , r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value){

        return true;
    }

    else{

        return false;
    }
}
int main(){

return 0;
}