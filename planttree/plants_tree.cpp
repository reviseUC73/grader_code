#include <iostream>
using namespace std;
struct Tree
{
    int row;
    int col;
    int index;
};
int main()
{
    int row = 0;
    int col = 0;
    int n = 0;
    // int max = 0;
    int min_index_k = n + 2;
    int max_same = 0;
    cin >> row >> col >> n;
    struct Tree box[n];
    for (int i = 0; i < n; i++)
    {
        int r=0, c=0;
        cin >> r;
        cin >> c;
        Tree tree;
        tree.row = r;
        tree.col = c;
        tree.index = i + 1;
        box[i] = tree;
    }
    for (int i = 0; i < n; i++)
    {
        int same = 0;
        for (int j = i; j < n; j++)
        {
            if (box[i].row == box[j].row)
            {
                same+=1;
                // cout<<box[j].row << box[j].col<<" row "<<box[j].index<<endl;
            }
            if (box[i].col == box[j].col)
            {
                same+=1;
                // cout<<box[j].row << box[j].col<<" col "<<box[j].index<<endl;
                
            }
        }
        // cout << same << "==<k>" << i + 1 << endl;
        if (max_same <= same)
        {
            max_same = same;
            int current_k = box[i].index;
            if (min_index_k < current_k)
            {
                min_index_k = current_k;
            }
        }
    }
    cout << min_index_k << max_same;
}
