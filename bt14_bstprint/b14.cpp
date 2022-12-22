#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
struct btsNode
{
    int value;
    struct btsNode *left;
    struct btsNode *right;
    btsNode(int v, btsNode *left = NULL, btsNode *right = NULL)
        : value(v), left(left), right(right) {}
};
void print_node(btsNode *tree, int level)
{
    if (tree != NULL)
    {
        print_node(tree->left, level + 1);
        for (int i = 0; i < level; i++)
        {
            cout << "...";
        }
        cout << "* " << tree->value << endl;
        print_node(tree->right, level + 1);
    }
}
btsNode *Insert(btsNode *tree, int num)
{
    btsNode *new_node = new btsNode(num);
    if (tree == NULL)
    {
        tree = new_node;
    }
    else if (num >= (tree)->value)
    {
        tree->left = Insert(tree->left, num);
    }
    else if (num <= (tree)->value)
    {
        (tree)->right = Insert(tree->right, num);
    }
    return tree;
}
bool search(btsNode *tree, int num)
{
    if (!tree)
    {                 // cout << "not find";
        return false; // lastest it not found
    }

    if (tree->value == num)
    {
        // cout << tree->value;
        return true;
    }
    else if (num > tree->value)
    {
        // cout << " --> " << tree->value<< " ";
        return search(tree->left, num); // gogogogo
    }
    else
    {
        // cout << " --> " << tree->value<< " ";
        return search(tree->right, num); // gogogogo
    }
}
int main()
{
    btsNode *tree = NULL;
    // int n, val, level = 0;
    // cin >> n;
    int k, level = 0;
    level = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int num, ch = 0;
        cin >> ch;
        cin >> num;
        if (ch == 1)
        {
            tree = Insert(tree, num);
        }
        if (ch == 2)
        {
            cout << search(tree, num) << endl;
        }
    }
}
