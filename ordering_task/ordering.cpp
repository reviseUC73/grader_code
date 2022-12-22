#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <iterator>
using namespace std;
vector<int> adj[110]; // adj[0] = 0
multimap<int, int> step_ans;
vector<int> ans;
bool check_[110] = {false};
// vector<vector<int>> table[110]; //( vector < type keep  >) == vector[0] = vec[0,0,0,0,0,0] ,...., vector[109] =vec[0,0,0,0,0,0]
// void print_vec(vector<int> a)
// {
//     for(i = )
// }

void init(int m)
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u;
        cin >> v;
        adj[u - 1].push_back(v - 1);
    }
}

int yo(int head)
{
    check_[head] = true;

    for (int i = 0; i < adj[head].size(); ++i)
    {
        if (!check_[i])

        {
            cout<<adj[head][i]<<endl;
            // step_ans.insert(pair<int, int>(count,adj[head][i]));
            // yo(adj[head][i])
            yo(head);
        }
        ans.push_back(head+1);
        
    }
}

int main()
{
    int n, m, count = 0;
    cin >> n;
    cin>> m;

    while (!(n == 0 && m == 0))
    {
        init(n);
        for (int i = 0; i < n; i++)
        {
            if (!check_[i])
            {
                yo(i);
            }
    copy(ans.rbegin(), ans.rend(), ostream_iterator<int>(cout, " "));

        }

    copy(ans.rbegin(), ans.rend(), ostream_iterator<int>(cout, " "));
    cin >> n;
    cin>> m;
    }
    return 0;
}

// bool x[110];
// x = 