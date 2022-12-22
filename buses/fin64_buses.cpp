#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 209000;
bool seen[MAX];
int weight_s[MAX];
vector<int> adj[MAX];
bool can_go = false;

void dfs(int start, int stop, int pow)
{
    // can go when >> if bus h1(cur_h + p) more h2 then ->  h2 is stop
    // can go when >> bus h1 more h2 and h2 is stop
    if (can_go)
        return;
    int cur_h;
    cur_h = weight_s[start];
    seen[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        int v_next = adj[start][i];
        if (cur_h + pow >= weight_s[v_next] and !seen[v_next])
        {   
            cout<<start+1<<" --> "<<v_next+1<<endl;

            if (v_next == stop)
            {
                can_go = true;
            }
            dfs(v_next, stop, pow);
        }
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> weight_s[i];
    }
    for (int u = 0; u < m; u++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // num loop for number of questions

    for (int u = 0; u < q; u++)
    {
        memset(seen, false, n + 10);
        can_go = false;
        int s, t, p;
        cin >> s >> t >> p;

        s--;
        t--;

        dfs(s,t,p);
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




void dfs(int start)
{
    seen[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        int v_next = adj[start][i];
        if (!seen[v_next])
        {   
            dfs(v_next);
        }
    }
}

// void dfs()
// {
//     bool visit[3010];
//     for (int i = 0; i < n; i++)
//         visit[i] = false;

//     stacknumber.push(deg[0]);
//     while (!(stacknumber.empty())) {
//         int v = stacknumber.top();
//         stacknumber.pop();
//         if (visit[v] == true) {continue;}

//         cout << v+1 << " ";
//         visit[v] = true;

//         for (int i = 0; i < adj[v].size(); i++) {
//             stacknumber.push(adj[v][i]);
//         }
//     }
// }
 
