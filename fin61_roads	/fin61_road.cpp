#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 209000;
bool seen[MAX];
vector<pair<int, int>> adj[MAX];
bool can_go = false;

void dfs(int start, int stop, int s)
{
    if (can_go)
        return;
    seen[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        int in_city, min_speed_road;

        in_city = adj[start][i].first;
        min_speed_road = adj[start][i].second;

        // cout << adj[start][i].second << endl;
        // cout<<in_city<<" "<<min_speed_road<<endl;

        //  you never go in city and your speed more than limit --> of course you can go check your
        if (!seen[in_city] and min_speed_road <= s) 
        {
            if (in_city == stop)
            {
                can_go = true;
            }
            // cout << "in_city: " << in_city+1 << " stop: " << stop+ 1 << endl;
            dfs(in_city, stop, s);
        }
    }
}

int main()
{
    int n, m, s, q;
    cin >> n >> m >> s >> q;
    for (int u = 0; u < m; u++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        x--;
        y--;

        adj[x].push_back(make_pair(y, l));
        adj[y].push_back(make_pair(x, l));
    }

    // num loop for number of questions
    for (int u = 0; u < q; u++)
    {
        memset(seen, false, n + 10);
        can_go = false;
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        dfs(a, b, s);
        if (can_go)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
