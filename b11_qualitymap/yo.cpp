#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<string> v;
    string s = "one";
    v.push_back(s);

    s = "two";
    v.push_back(s);
    s = "three";
    v.push_back(s);
    for (int i = 0; i < v.size(); ++i)
    {
        // cout << v[i][0] << '\n';
        for(int j = 0; j < v.size(); ++j)
        {
            cout << v[i][j] << '\n';
            if(v[i][j] == 'a')
            {
                v[i][j] = 'b';
            }
        }   
    }

}