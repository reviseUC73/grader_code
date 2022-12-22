#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 209000;
bool seen[MAX];
vector<pair<int, int>> adj[MAX];
bool can_go = false;
int max_ans = 0;

int level = 0;
void dfs(int start, int stop, int h)
{

    if (can_go)
        return;
    seen[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        int in_tun, max_h;

        in_tun = adj[start][i].first;
        max_h = adj[start][i].second;
        // cout <<start+1 <<  " -> "<< in_tun+1<< "  H : " << h <<" < "<<max_h  <<  endl;
        // cout << start + 1 << " -> " << in_tun + 1 << "  H : " << h << " < " << max_h << endl;

        //  you never go in city and your speed more than limit --> of course you can go check your
        if (!seen[in_tun] and (h <= max_h))
        {
            // cout <<" " <<start + 1 << " -> " << in_tun + 1 << "  H : " << h << " < " << max_h;

            level++;
            if (in_tun == stop)
            {
                // level++;
                can_go = true;
            }
            // cout << "level : " << level;
            // cout << "in_tunt " << in_tun+1 << " stop: " << stop+ 1 << endl;
            dfs(in_tun, stop, h);
        }

        // else
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int u = 0; u < m; u++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;

        adj[a].push_back(make_pair(b, l));
        adj[b].push_back(make_pair(a, l));
    }

    // num loop for number of questions

    // memset(seen, false, n + 10);
    // can_go = false;
    int s, t, h;
    cin >> s >> t >> h;

    s--;
    t--;
    dfs(s, t, h);
    // for (int i = 0; i <m; i++)
    // {
    //     can_go = false;
    //     level = 0;
    //     memset(seen, false, n + 10);
    //     // int start = adj[s][i].first;
    //     dfs(i, t, h);
    //     if (max_ans > level and can_go)
    //     {
    //         max_ans = level;
    //     }
    //     cout<<endl;
    // }
    // if (can_go)
    // {
    //     cout << "yes" << endl;
    // }
    // else
    // {
    //     cout << "no" << endl;
    // }
    if (!can_go)
    {
        cout << -1;
    }
    else
    {
        cout << max_ans;
    }

    return 0;
}
