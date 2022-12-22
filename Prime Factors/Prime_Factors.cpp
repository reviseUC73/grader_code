#include <iostream>
using namespace std;
bool check_prime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// int next_prime(int num) {

// }

int main()
{
    int num;
    int count = 0;
    cin >> num;
    for (int i = 1; i < num + 1; i++)
    {
        if (num % i == 0 and check_prime(i))
        {   
            count += 1;
        }
    }
    cout<<count-1;
}