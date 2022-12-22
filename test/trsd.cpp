#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<string> words;
    string inputString;
    while (cin >> inputString)
    {
        words.push_back(inputString);
    }

    vector<string>::iterator it;
    for (it = words.begin(); it != words.end(); it++)
    {
        cout << *it << "\n";
    }

    return 0;
}
