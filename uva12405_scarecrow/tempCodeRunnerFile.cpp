#include <iostream>
using namespace std;
int zero[30] = {0};

int main()
{
    // int zone[30] ;
    // zone = 0;
    zero[3] = 3;
     for (int i = 0; i < 30; i++)
    {
        cout << zero[i] << endl;
    }
}


