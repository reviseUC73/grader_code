#include <iostream>
#include<vector>
using namespace std;
int max = 1000;
vector<vector<string>>area;
// string are = "owfkfowk";
void addEdge(vector<vector<string>>area, int u, string v)
{
    area[u].push_back(v);
    // adj[v].push_back(u);
}
int main()
{   
    int row , column;
    cin >> row >> column;
    for(int u = 0; u < row; u++)
    {
        for(int v = 0; v < column; v++)
        {                                               //  v is the edge   between u and v
            cin >> area[u][v]; // add edge -> aree[u] = { string(a,b,ca,), string(a,b,ca,),string(a,b,ca,),string(a,b,ca,)}
        }
    // cout << area[4]<<endl;
}