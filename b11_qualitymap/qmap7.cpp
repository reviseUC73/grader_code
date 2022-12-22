#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// int zero[30] = {0};
// 
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
        }
    }
    int x, y = 0;
    int val = 0;
    int zone[10] = {0};
    set<char> type[10];
    

    for (int i = 0; i < u; i++)
    {   cout<<endl;
        int co = 0;

        
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] == '#')  
            {
                co++;
                cout<<"#";
                while (graph[i][j] == '#')
                {
                    j+=1;
                }
            }
            else
            {   
                cout << graph[i][j];
                zone[co] += 1;
                if (graph[i][j] == '*')
                {
                    type[co].insert('*');
                }
                else
                {
                    if (graph[i][j] == '*')
                    {
                        type[co].insert('*');
                    }
                    else if (graph[i][j] == '$')
                    {
                        type[co].insert('$');
                    }
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        // int zone[10] = {0};
        cout << zone[i] << endl;
    }           
}

    // while (!visit[u][v])
    // {
    //     set<char> type;
    //     if (x >= v)
    //     {
    //         y++;
    //         x = 0;
    //     }
    //     if (!visit[y][x])
    //     {
    //         x++;
    //     }
    //     visit[y][x] = true;

    //     if (graph[y][x] != '#')
    //     {

    //         if (graph[y][x] == '*')
    //         {
    //             type.insert('*');
    //         }
    //         else if (graph[y][x] == '$')
    //         {
    //             type.insert('$');
    //         }
    //         val += 1;
    //         x++;
    //     }
    //     else
    //     {

    //     }
    //         }
    //     }
    // }
