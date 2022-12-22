#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int f = n;
    while (n--)
    {
        int c;
        cin >> c;
        int case_ = 0;

        vector<char> buf(c);
        for (int i = 0; i < c; i++)
        {
            cin >> buf[i];
        }
        for (int i = 0; i < c;i++) //0
        {   
           
            
             if (buf[i] == '.') // -1in
            {
                case_ += 1;
                i+=2;
            }
            
            
        }
        cout <<"Case "<< f-n <<": "<< case_ << endl;
    
    }
}