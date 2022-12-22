#include <iostream>
#include <list>
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
// struct btsNode *tree;
// btsNode *Insert(btsNode *tree, int num)
// {
//     btsNode *new_node = new btsNode(num);
//     if (tree == NULL)
//     {
//         // btsNode *new_node = new btsNode(num);
//         tree = new_node;
//         // cout<<"* "<< tree->value<<endl;
//     }
//     else if (num >= (tree)->value)
//     {
//         // cout<<"...";
//         tree->left = Insert(tree->left, num);
//     }
//     else if (num <= (tree)->value)
//     {
//         // cout<<"...";
//         (tree)->right = Insert(tree->right, num);
//     }
//     // cout<<"...";

//     return tree;
// }
void Insert(btsNode *&tree, int num)
{
    btsNode *new_node = new btsNode(num);
    if (tree == NULL)
    {
        tree = new_node;
        ;
    }
    else if (num < (tree)->value)
    {
        Insert(tree->left, num);
    }
    else if (num > (tree)->value)
    {
        Insert(tree->right, num);
    }
}

// void Insert(btsNode*& r, int x)
// {
//     if(!r)
//         r = new btsNode(x);

//     else if(x < r->value)
//         Insert(r->left, x);
//     else if(x > r->value)
//         Insert(r->right,x);
// }
bool search(btsNode *tree, int num)
{
    if (!tree)
    {
        // cout << "not find";

        return false; // lastest it not found
    }

    if (tree->value == num)
    {
        // cout << tree->value;
        return true;
    }
    else if (num < tree->value)
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
    btsNode *w = nullptr;
    // int n, val, level = 0;
    // cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int num, ch = 0;
        cin >> ch;
        cin >> num;
        if (ch == 1)
        {
            Insert(w, num);
        }
        else
        {
            cout << search(w, num) << endl;
        }
        // else
        // {
        //     if (search(tree, num))
        //         cout << "1" << endl;
        //     else
        //         cout << "0" << endl;
        // }
    }
}
// int main()
// {
//     list<int> mylist;
//     list<int>::iterator it = mylist.begin();
//     int k;
//     cin >> k;
//     for (int i = 0; i < k; i++)
//     {
//         int num, ch = 0;
//         cin >> ch;
//         cin >> num;

//         if (ch == 1)
//         {
//             mylist.insert(it, num);
//         }
//         else if (ch == 2)
//         {
//             bool found = (find(mylist.begin(), mylist.end(), num) != mylist.end());
//             cout << found << endl;
//         }
//     }
// }
