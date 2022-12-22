#include <iostream>
#include <set>
using namespace std;
struct btsNode
{
    int value;
    struct btsNode *left;
    struct btsNode *right;
    btsNode(int v, btsNode *left = NULL, btsNode *right = NULL)
        : value(v), left(left), right(right) {}
};
struct btsNode *tree;
btsNode *Insert(btsNode *tree, int num)
{
    btsNode *new_node = new btsNode(num);
    if (tree == NULL)
    {

        // btsNode *new_node = new btsNode(num);
        tree = new_node;
        // cout<<"* "<< tree->value<<endl;
    }
    else if (num >= (tree)->value)
    {
        // cout<<"...";
        tree->left = Insert(tree->left, num);
    }
    else if (num <= (tree)->value)
    {
        // cout<<"...";
        (tree)->right = Insert(tree->right, num);
    }
    // cout<<"...";

    return tree;
}
void print_node(btsNode *tree, int level)
{
    if (tree != NULL)
    {
        print_node(tree->left,level+1);
        for(int i=0 ; i<level;i++)
        {
            cout<<"...";
        }
        cout << "* " << tree->value << endl;
        print_node(tree->right,level+1);

    }

    // if (tree->right == NULL and tree->left == NULL)
    // {
    //     return;
    //     // cout << "* " << tree->value << endl;
    // }
    // else if (tree->right != NULL)
    // {
    //     for (size_t i = 0; i < level ; i++)
    //     {
    //         cout<<"...";
    //     }
    //     print_node(tree->right,level+1); // right not null then we can go right
    // }
    // else if (tree->left != NULL)
    // {
    //     for (size_t i = 0; i < level ; i++)
    //     {
    //         cout<<"...";
    //     }
    //     print_node(tree->left,level+1);
    // }
    // cout << "* " << tree->value << endl;
}

int main()
{
    btsNode *tree = NULL;
    int n, val, level = 0;
    cin >> n;
    for (int i; i < n; i++)
    {
        cin >> val;
        tree = Insert(tree, val);
    }
    print_node(tree, level);
}