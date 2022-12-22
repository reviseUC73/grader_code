#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int max = 1000;
// int zero[30] = {0};

// void init()
// string are = "owfkfowk";
// void chargraph()
//     {
//         string s;
//         cin >> s;
//         for (int i = 0; i < s.length(); i++)

//             if (s[i] == '0')
//                 zero[i] = 1;
//             else{

//             }
//     }
// void print_graph(int u,int v ,string graph[])
// {
//      for (size_t i = 0; i < u; i++)
//     {
//         cout << i << " : " ;
//         for (size_t j = 0; j < v; j++)
//     {
//         /* code */cout<<graph[i][j]<<" ";
//     }
//     cout << endl;   //  end code
//     }
// void print_graph(){
//     for (int i = 0; i < max; i++)
//     {

// }
// void dfs
int main()
{
    int u, v;
    cin >> u >> v;

    char graph[u][v];
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
            // char x;
            // cin >> x;

            // if (graph[i][j] == '#')
            // {
            //     j++;
            //     graph[i][j] = '0';
            // }
            // graph[i][j] = x;
        }
    }
    // for (int i = 0; i < u; i++)
    // {
    //     for (int j = 0; j < v; j++)
    //     {
    //         if (graph[i][j] != '#')
    //         {

    //         }
    //     }
    // }
    int x, y = 0;
    int val = 0;
    int zone[10] = {0};
    // int
    bool visit[u][v];

    while (!visit[u][v])
    {
        set<char> type;

        visit[y][x] = true;
        
        if (graph[y][x] != '#')
        {

            if (graph[y][x] == '*')
            {
                type.insert('*');
            }
            else if (graph[y][x] == '$')
            {
                type.insert('$');
            }
            val += 1;
            x++;
        }
        else
        {
            
        }
    }
}
