#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cd1, cd2;
    cin >> cd1 >> cd2;
    while (cd1 != 0 and cd2 != 0)
    {
        int k = 0;
        vector<int> box1, box2;
      
        for (int i = 0; i < cd1; i++)
        {
            int num;
            cin >> num;
            // cin >> box1[i];
            box1.push_back(num);
        }
        for (int i = 0; i < cd2; i++)
        {
            // cin >> box2[i];
            int num2;
            cin >> num2;
            // cin >> box1[i];
            box2.push_back(num2);
        }

        if (cd1 < cd2)
        {
            for (int i = 0; i < cd1; i++)
            {
                if (binary_search(box2.begin(), box2.end(), box1[i])) // *box1.end() == 0
                {

                    k++;
                }
            }
        }
        else{
            for (int i = 0; i < cd2; i++)
            {
                if (binary_search(box1.begin(), box1.end(), box2[i])) // *box1.end() == 0
                {
                    k++;
                }
            }
        }

        cout << k << endl;
        cin >> cd1 >> cd2;
    }
}
