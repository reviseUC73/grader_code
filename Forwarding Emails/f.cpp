#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visit_[50500];

vector<int> adj[50500]; // adj[0] = list[], adj[1] = adj[]

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);

}

