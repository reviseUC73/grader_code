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

        vector<char> buf(c+3);
        for (int i = 0; i < c; i++)
        {
            cin >> buf[i];
        }
        for (int i = 0; i < c;) //0
        {   
            if (buf[i + 2] == '.' and buf[i] == '.') // -1-in3-_4-_5 ->in pos to check 0,
            { 
                case_ += 1; 
                i += 3; // 2 -> check 2
            }
            else if (buf[i + 1] == '.') // -1-in3-_4-_5 ->in pos to check 0,
            { 
                case_ += 1; 
                i += 3; // 2 -> check 2
            }
            else if (buf[i] == '.') // -1in
            {
                // cout<<"you3";
                case_ += 1;
                i += 3; // 1 //skip
            }
             else if (buf[i+2] == '.') // -1in
            {
                // cout<<"you";
                case_ += 1;
                i += 4; // 1 //skip
            }
           
            else
            {
                i+=3;
            }
            if(buf[i]=='#')
            {
                i++;
            }
        }
        cout <<"Case "<< f-n <<": "<< case_ << endl;
    
    }
}
// #include <iostream>
// #include<vector>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int f = n;
//     while (n--)
//     {
//         int c;
//         cin >> c;
//         int case_ = 0;

//         vector<char> buf(c);
//         for (int i = 0; i < c; i++)
//         {
//             cin >> buf[i];
//         }
//         for (int i = 0; i < c;i++) //0
//         {   
//             if (buf[i + 2] == '.' and buf[i] == '.') // -1-in3-_4-_5 ->in pos to check 0,
//             {
//                 case_ += 1; 
//             }
//             else if (buf[i + 1] == '.') // -1-in3-_4-_5 ->in pos to check 0,
//             {
//                 case_ += 1; 
//             }
//             else if (buf[i] == '.') // -1in
//             {
//                 case_ += 1;
//             }
//              else if (buf[i+2] == '.') // -1in
//             {
//                 case_ += 1;
//             }
//             i += 2; // 1 //skip
           
            
//         }
//         cout <<"Case "<< f-n <<": "<< case_ << endl;
    
//     }
// }