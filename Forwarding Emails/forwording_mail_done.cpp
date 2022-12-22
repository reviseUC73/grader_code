#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int Case, Max, a, b;
vector<int> graph;
vector<int> sum;
vector<bool> check_vis;

int dfs(int u)
{
    int total = 0;
    check_vis[u] = true;
    if (graph[u] != -1)
    {
        if (!check_vis[graph[u]])
        {
            total += (1 + dfs(graph[u]));
        }
    }
    check_vis[u] = false;
    return  sum[u] = total;
}


int main()
{
    cin >> Case;
    
    for (int case_ = 1; case_ <= Case; case_++)
    {
        cin >> Max;
        graph.assign(Max, -1);
        sum.assign(Max, -1);
        check_vis.assign(Max, false);
        for (int i = 0; i < Max; i++)
        {
            cin >> a;
            cin >> b;

            graph[a - 1] = b - 1;
        }
        int get_ans = 0;
        int goodness_len = 0;
        for (int i = 0; i < Max; i++)
        {
            if (sum[i] == -1)
                dfs(i);
            if (sum[i] > goodness_len)
            {
                goodness_len = sum[i];
                get_ans = i;
            }
        }
        cout << "Case " << case_ <<": "<< get_ans + 1 << endl;
    }
}

