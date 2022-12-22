#include <iostream>
#include <vector>
#include <queue>

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
int main()
{
    int u, v;
    cin >> u >> v;

    char graph[u][v];
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < v; j++)
        {
            char x;
            cin >> x;
            
            if (x == '#')
            {
                i++;
            }
            // graph[i][j] = x;

        }

        return 0;
    }
