
#include <iostream>
#include <vector>
#include<algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

bool check_[150];
vector<vector<int>> adj(110);
vector<int> ans;

void top_sort(int x)
{
    check_[x] = true;

    for (int i = 0; i < (int)adj[x].size(); ++i)
    {
        int head = adj[x][i];
        if (!check_[head])
            top_sort(head);
    }

    ans.insert(ans.begin(), x + 1);
}
int main()
{
    int n, m, x, y;
    while (cin >> n >> m && n != 0)
    {
        adj.clear();
        ans.clear();
        memset(check_, false, sizeof check_);

        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            adj[x - 1].push_back(y - 1);
        }

        for (int i = 0; i < n; ++i)
            if (!check_[i])
                top_sort(i);

        for (int i = 0; i < (int)ans.size(); i++)
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }

    return 0;
}
