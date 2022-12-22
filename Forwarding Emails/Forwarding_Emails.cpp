#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visit_[50500];

vector<int> adj[50500]; // adj[0] = list[], adj[1] = adj[]

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
// adj[u][v]
void dfs(int u,int level)
{
    // if (visit_[u])
    //     return;
    visit_[u] = true;
    // dfs(u + 1);
    // visit_[u] = false;
    // in DFS in v
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i]; //   adj[i] = list[], adj[   i] = list
        // cout << "Look ()v : " << v << " :";
        cout<<level+1<<endl;
        if (!visit_[v])
        {   
            // cout<<level+1<<endl;
            visit_[v] = true;
            dfs(v,level+1);
        }
    }
    // cout <<" level :"<<level  << endl;
}
int main()
{
    int n;
    cin >>n;
    int level = 0   ;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    for(int i = 1; i <= n; i++){
        // if(!visit_[i]){
            dfs(i,level+1);
        // }
    }
}

// void DFS(int u){
//     visit_[u] = true;
//     int i = 0 ;

// }