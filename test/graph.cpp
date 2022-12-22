
#include <iostream>
#include <vector>
using namespace std;
vector<string> words;
vector<int> adj[100];
// void max_length(char V[])
void max_length(char V)

{
    cout << V;
}
int main()
{
    char V[] = {'v', 'b', 'x', 'z', 'a', 'y'};
    char E[] = {('b', 'y'), ('y', 'v'), ('z', 'a'), ('b', 'x'), ('x', 'v')}; // cost 2
                                                                             // G = (V, E)
    // return 0;
    max_length(V[2]);

    for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        cout << *it << "\n";
    }
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[2].push_back(3);
    cout << adj[0].size();
    cout << adj[2].size();
}
    // cout<<adj[0]; //bomb

    //     #include <iostream>
    // #include <algorithm>
    // #include <vector>
    // #include <list>

    // using namespace std;

    // int main()
    // {
    //     vector<string> words;
    //     string inputString;
    //     while (cin >> inputString)
    //     {
    //         words.push_back(inputString);
    //     }

    //     vector<string>::iterator it;
    //     for (it = words.begin(); it != words.end(); it++)
    //     {
    //         cout << *it << "\n";
    //     }

    //     return 0;
    // }

    //     // for(auto )
    //     // for(iterator i = E.begin(); i != E.end(); i++)
    // 
