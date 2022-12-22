#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // Read the number of groups and the string from the input
    int num_groups;
    string str;
    while (cin >> num_groups)
    {
        // Check if the input is terminated by a line containing a single zero
        if (num_groups == 0)
        {
            break;
        }

        cin >> str;

        // Reverse each group of the string
        int group_size = str.size() / num_groups;
        for (int i = 0; i < str.size(); i += group_size)
        {
            reverse(str.begin() + i, str.begin() + i + group_size);
        }

        // Print the group reversed string
        cout << str << endl;
    }

    return 0;
}