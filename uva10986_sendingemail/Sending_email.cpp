#include <iostream>
#include <vector>
#include <algorithm>



#define inf 1000000000
#define ii pair<int, int>

using namespace std;

int latency[20010];
int n, m, s, t;
vector< vector<ii> > adj;

void BellmanFord(int s)
{
    for(int i = 0; i<n; i++) latency[i] = inf;
    latency[s] = 0;
    bool updated = true;
    while(updated){
        updated = false;
        for(int u = 0; u<n; u++){
            for(int i = 0; i<adj[u].size(); i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if(latency[v] > latency[u] + w){
                    latency[v] = latency[u] + w;
                    updated = true;
                }
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    for(int k = 1; k<=tc; k++){
        cin >> n >> m >> s >> t;
        adj.assign(n, vector<ii>(0));
        int x, y, l;
        for(int i = 0; i<m; i++){
            cin >> x >> y >> l;
            adj[x].push_back( ii(y, l) );
            adj[y].push_back( ii(x, l) );
        }

        BellmanFord(s);
        cout << "Case #" << k << ": ";
        if(latency[t] != inf) cout << latency[t] << endl;
        else cout << "unreachable" << endl;
    }
}
