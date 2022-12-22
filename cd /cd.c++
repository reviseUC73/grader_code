#include <iostream>
using namespace std;

int main()
{

    int cd1, cd2;
    cin >> cd1;
    cin >> cd2;
    while (cd1 != 0 and cd2 != 0)
    {
        int box1[cd1];
        int num = 0;
        for (int i=0; i < cd1; i++)
        {
            cin >> box1[i];
        }
        for (int i= 0; i < cd2; i++)
        {
            int check2;
            cin >> check2;
            for (int k = 0; k < cd1; k++)
            {
                if (check2 == box1[k])
                {
                    num += 1;
                }
            }
        }
        cout <<num << endl;
        num = 0;
        cin >> cd1;
        cin >> cd2; 
    }
}