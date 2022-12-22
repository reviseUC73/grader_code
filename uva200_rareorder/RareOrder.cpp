#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    vector<string> s;
    unordered_set<char> seen;
    string word;
    char c;

    while (cin >> word)
    {
        if (word == "#")
            break;

        s.push_back(word);
    }

    for (int i = 0; i < 20; i++)
    {
        for (const string& str : s)
        {
            if (i < str.length())
            {
                c = str[i];
                if (seen.find(c) == seen.end())
                {
                    cout << c;
                    seen.insert(c);
                }
            }
        }
    }
    cout << endl;

    return 0;
}
